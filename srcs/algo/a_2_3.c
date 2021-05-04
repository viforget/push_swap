/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_2_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:15:05 by viforget          #+#    #+#             */
/*   Updated: 2021/05/04 15:02:09 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_2(t_stacks stacks)
{
	if (stacks.a->nb > stacks.a->next->nb)
		stacks = print_op("sa", sa, stacks);
}

void	a_3(t_stacks s)
{
	if (s.a->nb > s.a->next->nb && s.a->next->nb > s.a->next->next->nb)
		s = print_op("sa", sa, s);
	if (s.a->nb < s.a->next->nb && s.a->next->nb > s.a->next->next->nb)
		s = print_op("rra", rra, s);
	if (s.a->next->nb < s.a->nb && s.a->nb < s.a->next->next->nb)
		s = print_op("sa", sa, s);
	if (s.a->next->nb < s.a->nb && s.a->nb > s.a->next->next->nb)
		s = print_op("ra", ra, s);
}