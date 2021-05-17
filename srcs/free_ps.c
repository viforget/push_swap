/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:36:55 by viforget          #+#    #+#             */
/*   Updated: 2021/05/17 16:48:01 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	*free_stack(t_stack *stack)
{
	t_stack	*buf;

	while (stack)
	{
		buf = stack;
		stack = stack->next;
		buf->next = NULL;
		free(buf);
	}
	return (NULL);
}

void	*free_stacks(t_stacks stacks)
{
	t_stack	*buf;

	while (stacks.a)
	{
		buf = stacks.a;
		stacks.a = stacks.a->next;
		free(buf);
	}
	while (stacks.b)
	{
		buf = stacks.b;
		stacks.b = stacks.b->next;
		free(buf);
	}
	return (NULL);
}
