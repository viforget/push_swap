/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:42:46 by lobertin          #+#    #+#             */
/*   Updated: 2021/05/07 12:06:36 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define DIV 11

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

/*t_stacks a2b(t_stacks stacks)
{
	int i;
	int size;

	i = 0;
	size = sizeoflist(stacks.b);
	while (!rcheck_list(stacks.b) && i < size - 1)
	{
		if (stacks.b->nb < stacks.b->next->nb)
		{
			printf("sb\n");
			stacks = sb(stacks);
			if (i > 0)
			{
				i--;
				printf("rrb\n");
				stacks = rrb(stacks);
			}
		}
		else
		{
			i++;
			printf("rb\n");
			stacks = rb(stacks);
		}
	//print_list(stacks.b, "B");
	}
	printf("rb\n");
	stacks = rb(stacks);
	print_list(stacks.b, "B");
	return (stacks);
}*/

void	random_name(t_stacks stacks)
{
	t_stack *buf; 
	int 	a;
	int 	b;
	int 	cnt;

	cnt = 0;
	buf = stacks.b;
	while(buf->next)
	{
		cnt++;
		if (buf->nb > buf->next->nb)
			b = cnt;
		if (stacks.a > buf->nb && stacks.a < buf->next->nb)
			a = cnt;
		buf = buf->next;
	}
	if ()
}

int		hold_second(t_stack *st, int min, int max)
{
	int	nb;
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
	return (x);
}

int		last_number(t_stack *stack)
{
	if (!stack->next)
		return (stack->nb);
	return (last_number(stack->next));
}

t_stacks	no_infinite(t_stacks stacks)
{
	int		min;
	int 	max;
	t_stack	*buf;

	buf = stacks.b;
	min = stacks.b->nb;
	max = stacks.b->nb;
	if (!stacks.a)
		return (stacks);
	while(buf)
	{
		if (min > buf->nb)
			min = buf->nb;
		if (max < buf->nb)
			max = buf->nb;
		buf = buf->next;
	}
	if (stacks.a->nb < min || stacks.a->nb > max)
		while (stacks.b->nb != max)
			stacks = print_op("rrb", rrb, stacks);
	else 
		while(stacks.b && stacks.b->next && (stacks.a->nb < stacks.b->nb || stacks.a->nb > last_number(stacks.b)))
			stacks = print_op("rrb", rrb, stacks);
	return (stacks);
}

t_stacks a4(t_stacks stacks)
{
	int		sizea;
	int		*tab;
	int		i;
	int		j;
	int		x;
	int		x2;
	t_stack *buff;
	
	sizea = sizeoflist(stacks.a);
	tab = malloc(sizeof(int)* sizea);
	i = 0;
	buff = stacks.a;

	while (buff != NULL)
	{
		tab[i++] = buff->nb;
		buff = buff->next;
	}
	tab = tri(tab, sizea);
	
	i = 0;
	j = 0;
	while (i <= 11)
	{
		while (j < sizea / 11 * (i + 1))
		{
			buff = stacks.a;
			x = 0;
			while (buff && (buff->nb < tab[(sizea / DIV) * i] || buff->nb > tab[(sizea / DIV) * (i + 1)]))
			{
				x++;
				buff = buff->next;
			}
			x2 = sizea - hold_second(stacks.a, (sizea / DIV) * i, (sizea / DIV) * (i + 1)) - 1;
			if (x2 > x)
				while (x--)
					stacks = print_op("ra", ra, stacks);
			else
				while (x2--)
					stacks = print_op("rra", rra, stacks);
			if (stacks.b)
				stacks = no_infinite(stacks);
			stacks = print_op("pb", pb, stacks);
			j++;
		}
		i++;
	}
	while (stacks.b->nb != tab[sizea - 1])
		stacks = print_op("rb", rb, stacks);
	while (stacks.b)
		stacks = print_op("pa", pa, stacks);
	print_list(stacks.a, "A");
	print_list(stacks.b, "B");
	return(stacks);
}
