/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a4.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:42:46 by lobertin          #+#    #+#             */
/*   Updated: 2021/05/16 19:37:32 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	scroll_b(t_stacks stacks, int nb)
{
	t_stack	*buf;
	int		a;
	int		cnt;

	cnt = sizeoflist(stacks.b);
	a = get_a(stacks.b, nb);
	if (a * 2 < (cnt * 2) / 2)
		stacks = rotate_until(stacks, a);
	else
		stacks = rrotate_until(stacks, cnt - a);
	return (stacks);
}

t_stacks	witch_sens(t_stacks stacks, int a, int x, int dir)
{
	int	cnt;

	cnt = sizeoflist(stacks.b);
	while (x--)
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

t_stacks	scroll_a(t_stacks stacks, int x, int dir)
{
	int	nb;
	int	cnt;
	int	a;

	if (dir == 1)
		nb = nb_in_list(stacks.a, x);
	else
		nb = nb_in_list(stacks.a, sizeoflist(stacks.a) - x);
	a = get_a(stacks.b, nb);
	stacks = witch_sens(stacks, a, x, dir);
	return (stacks);
}

t_stacks	loop_scroll(t_stacks stacks, int sizea, int *tab)
{
	int	i[2];
	int	x[2];

	i[0] = 0;
	i[1] = 0;
	while (i[0]++ <= 11)
	{
		while (i[1] < sizea / 11 * (i[0]) && stacks.a)
		{
			x[0] = hold_first(stacks.a, tab[((sizea / 11) * (i[0] - 1))],
					tab[((sizea / 11) * (i[0]))]);
			x[1] = hold_second(stacks.a, tab[((sizea / 11) * (i[0] - 1))],
					tab[((sizea / 11) * (i[0]))]);
			if (x[1] > x[0])
				stacks = scroll_a(stacks, x[0], 1);
			else
				stacks = scroll_a(stacks, x[1], 2);
			if (stacks.b && stacks.a)
				stacks = scroll_b(stacks, stacks.a->nb);
			if (stacks.a)
				stacks = print_op("pb", pb, stacks);
			i[1]++;
		}
	}
	return (stacks);
}

t_stacks	a4(t_stacks stacks)
{
	int		sizea;
	int		*tab;

	sizea = sizeoflist(stacks.a);
	tab = lst_to_tab(stacks.a, 1);
	stacks = loop_scroll(stacks, sizea, tab);
	stacks = scroll_b(stacks, tab[0] - 1);
	while (stacks.b)
		stacks = print_op("pa", pa, stacks);
	free(tab);
	return (stacks);
}
