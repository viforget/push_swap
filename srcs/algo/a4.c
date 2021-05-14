/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:42:46 by lobertin          #+#    #+#             */
/*   Updated: 2021/05/14 18:26:27 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rcheck_list(t_stack *list)
{
	int	nb;

	while (list->next)
	{
		nb = list->nb;
		list = list->next;
		if (nb <= list->nb)
			return (0);
	}
	return (1);
}

t_stacks	rrotate_until(t_stacks stacks, int nb)
{
	while (nb-- > 0)
		stacks = print_op("rrb", rrb, stacks);
	return (stacks);
}

t_stacks	rotate_until(t_stacks stacks, int nb)
{
	while (nb-- > 0)
		stacks = print_op("rb", rb, stacks);
	return (stacks);
}

t_stacks	scroll_b(t_stacks stacks, int nb)
{
	t_stack	*buf;
	int		a;
	int		b;
	int		cnt;

	cnt = 1;
	a = -1;
	b = 0;
	buf = stacks.b;
	while (buf->next)
	{
		cnt++;
		if (buf->nb < buf->next->nb)
			b = cnt - 1;
		if (nb < buf->nb && nb > buf->next->nb)
			a = cnt - 1;
		buf = buf->next;
	}
	if (buf->nb < stacks.b->nb)
		b = cnt;
	if (nb < buf->nb && nb > stacks.b->nb)
		a = 0;
	//printf("b %d %d %d\n", cnt, a == -1 ? b : a, nb);
	//print_list(stacks.b, "BB");
	if (a == -1)
	{
		if (b * 2 < (cnt * 2) / 2)
			stacks = rotate_until(stacks, b);
		else
			stacks = rrotate_until(stacks, cnt - b);
	}
	else if (a * 2 < (cnt * 2) / 2)
		stacks = rotate_until(stacks, a);
	else
		stacks = rrotate_until(stacks, cnt - a);
	return (stacks);
}

int		get_a(t_stack *st, int nb)
{
	int cnt;
	int a;
	int b;

	a = -1;
	b = 0;
	cnt = 0;
	if (!st)
		return (0);
	while(st && st->next)
	{
		cnt++;
		if (st->nb < st->next->nb)
			b = cnt - 1;
		if (nb < st->nb && nb > st->next->nb)
			a = cnt - 1;
		st = st->next;
	}
	if (st->nb < st->nb)
		b = cnt;
	if (nb < st->nb && nb > st->nb)
		a = 0;
	if (a == -1)
		return (b);
	return (a);
}

t_stacks	scroll_a(t_stacks stacks, int x, int dir)
{
	int nb;
	int cnt;
	int a;

	if (dir == 1)
		nb = nb_in_list(stacks.a, x);
	else
		nb = nb_in_list(stacks.a, sizeoflist(stacks.a) - x);
	a = get_a(stacks.b, nb);
	cnt = sizeoflist(stacks.b);
	//printf("a %d %d %d %d\n", cnt, a, x, nb);
	//print_list(stacks.a, "AA");
	//print_list(stacks.b, "BA");
	while(x--)
	{
		if (dir == 1)
		{
			if (a * 2 < (cnt * 2) / 2 && a-- > 0)
				stacks = print_op("rr", rr, stacks);
			else
				stacks = print_op("ra", ra, stacks);
		}
		else
		{
			if (a * 2 >= (cnt * 2) / 2 && a++ < cnt)
				stacks = print_op("rrr", rrr, stacks);
			else
				stacks = print_op("rra", rra, stacks);
		}
	}
	return (stacks);
}

int	hold_second(t_stack *st, int min, int max)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (st)
	{
		if (st->nb >= min && st->nb < max)
			x = i;
		i++;
		st = st->next;
	}
	return (i - x);
}

int	hold_first(t_stack *st, int min, int max)
{
	int	x;

	x = 0;
	//printf("%d %d\n", min, max);
	while (st && (st->nb < min || st->nb > max))
	{
		x++;
		st = st->next;
	}
	return (x);
}

int	last_number(t_stack *stack)
{
	if (!stack->next)
		return (stack->nb);
	return (last_number(stack->next));
}

t_stacks	a4(t_stacks stacks)
{
	int		sizea;
	int		*tab;
	int		i;
	int		j;
	int		x;
	int		x2;

	sizea = sizeoflist(stacks.a);
	tab = lst_to_tab(stacks.a, 1);
	i = 0;
	j = 0;
	while (i <= 11)
	{
		while (j < sizea / 11 * (i + 1))
		{
			x = hold_first(stacks.a, tab[(sizea / 11) * i], tab[(sizea / 11) * (i + 1)]);
			x2 = hold_second(stacks.a, tab[(sizea / 11) * i], tab[(sizea / 11) * (i + 1)]);
			if (x2 > x)
				stacks = scroll_a(stacks, x, 1);
				//while (x--)
				//	stacks = print_op("ra", ra, stacks);
			else
				stacks = scroll_a(stacks, x2, 2);
				//while (x2--)
				//	stacks = print_op("rra", rra, stacks);
			if (stacks.b && stacks.a)
			{
				stacks = scroll_b(stacks, stacks.a->nb);
			}

			if (stacks.a) //PAS NECESSAIRE
				stacks = print_op("pb", pb, stacks);
			j++;
		}
		i++;
	}
	stacks = scroll_b(stacks, tab[0] - 1);
	while (stacks.b)
		stacks = print_op("pa", pa, stacks);
	return (stacks);
}
