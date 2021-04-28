/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:24:47 by viforget          #+#    #+#             */
/*   Updated: 2021/04/28 15:24:49 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	rra(t_stacks stacks)
{
	t_stack *buf;
	t_stack *buf2;

	buf = stacks.a;
	buf2 = buf;
	stacks.a = stacks.a->next;
	while(buf2->next)
		buf2 = buf2->next;
	buf2->next = buf;
	buf->next = NULL;
	return (stacks);
}

t_stacks	rrb(t_stacks stacks)
{
	t_stack *buf;
	t_stack *buf2;

	buf = stacks.b;
	buf2 = buf;
	stacks.b = stacks.b->next;
	while(buf2->next)
		buf2 = buf2->next;
	buf2->next = buf;
	buf->next = NULL;
	return (stacks);
}

t_stacks	rrr(t_stacks stacks)
{
	stacks = ra(stacks);
	stacks = rb(stacks);
	return (stacks);
}