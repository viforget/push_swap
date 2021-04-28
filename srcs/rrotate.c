/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:24:47 by viforget          #+#    #+#             */
/*   Updated: 2021/04/28 15:38:42 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	rra(t_stacks stacks)
{
	t_stack *buf;
	t_stack *buf2;

	if (!stacks.a)
		return (stacks);
	buf = stacks.a;
	buf2 = buf->next;
	while(buf2->next)
	{
		buf = buf->next;
		buf2 = buf->next;
	}
	buf->next = NULL;
	buf2->next = stacks.a;
	stacks.a = buf2;
	return (stacks);
}

t_stacks	rrb(t_stacks stacks)
{
	t_stack *buf;
	t_stack *buf2;

	if (!stacks.b)
		return (stacks);
	buf = stacks.b;
	buf2 = buf->next;
	while(buf2->next)
	{
		buf = buf->next;
		buf2 = buf->next;
	}
	buf->next = NULL;
	buf2->next = stacks.a;
	stacks.b = buf2;
	return (stacks);
}

t_stacks	rrr(t_stacks stacks)
{
	stacks = rra(stacks);
	stacks = rrb(stacks);
	return (stacks);
}