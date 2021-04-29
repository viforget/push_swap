/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:24:47 by viforget          #+#    #+#             */
/*   Updated: 2021/04/29 14:04:42 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*int 	print_list(t_stack *list)
{
	while (list->next)
	{
		list = list->next;
		printf("%d ", list->nb);
	}
	printf("\n");
	return (1);
}*/


t_stacks	rra(t_stacks stacks)
{
	t_stack	*buf;
	t_stack	*buf2;

	if (!stacks.a)
		return (stacks);
	buf = stacks.a;
	while (buf->next->next)
		buf = buf->next;
	buf2 = buf->next;
	buf->next = NULL;
	buf2->next = stacks.a;
	stacks.a = buf2;
	return (stacks);
}

t_stacks	rra(t_stacks stacks)
{
	t_stack	*buf;
	t_stack	*buf2;

	if (!stacks.b)
		return (stacks);
	buf = stacks.b;
	while (buf->next->next)
		buf = buf->next;
	buf2 = buf->next;
	buf->next = NULL;
	buf2->next = stacks.b;
	stacks.b = buf2;
	return (stacks);
}

t_stacks	rrr(t_stacks stacks)
{
	stacks = rra(stacks);
	stacks = rrb(stacks);
	return (stacks);
}