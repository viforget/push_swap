/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:24:54 by viforget          #+#    #+#             */
/*   Updated: 2021/04/28 15:25:33 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	sa(t_stacks stacks)
{
	int nb;

	if (!stacks.a)
		return (stacks);
	nb = stacks.a->nb;
	stacks.a->nb = stacks.a->next->nb;
	stacks.a->next->nb = nb;
	return(stacks);
}

t_stacks	sb(t_stacks stacks)
{
	int nb;

	if (!stacks.b)
		return (stacks);
	nb = stacks.b->nb;
	stacks.b->nb = stacks.b->next->nb;
	stacks.b->next->nb = nb;
	return(stacks);
}

t_stacks	ss(t_stacks stacks)
{
	stacks = sa(stacks);
	stacks = sb(stacks);
	return(stacks);
}