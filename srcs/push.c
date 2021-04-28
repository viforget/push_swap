/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:24:52 by viforget          #+#    #+#             */
/*   Updated: 2021/04/28 15:25:34 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	pa(t_stacks stacks)
{
	t_stack *buf;

	if (stacks.b)
	{
		buf = stacks.b;
		stacks.b = stacks.b->next;
		buf->next = stacks.a;
		stacks.a = buf;
	}
	return(stacks);
}

t_stacks	pb(t_stacks stacks)
{
	t_stack *buf;

	if (stacks.a)
	{
		buf = stacks.a;
		stacks.a = stacks.a->next;
		buf->next = stacks.b;
		stacks.b = buf;
	}
	return(stacks);
}