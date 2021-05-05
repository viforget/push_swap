/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_2_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 14:15:05 by viforget          #+#    #+#             */
/*   Updated: 2021/05/05 14:09:57 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	a_2(t_stacks stacks)
{
	if (stacks.a->nb > stacks.a->next->nb)
		stacks = print_op("sa", sa, stacks);
	return (stacks);
}

t_stacks	a_3(t_stacks s)
{
	if (s.a->nb > s.a->next->nb && s.a->next->nb > s.a->next->next->nb)
		s = print_op("sa", sa, s);
	if (s.a->nb < s.a->next->nb && s.a->next->nb > s.a->next->next->nb)
		s = print_op("rra", rra, s);
	if (s.a->next->nb < s.a->nb && s.a->nb < s.a->next->next->nb)
		s = print_op("sa", sa, s);
	if (s.a->next->nb < s.a->nb && s.a->nb > s.a->next->next->nb)
		s = print_op("ra", ra, s);
	return (s);
}