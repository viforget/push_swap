/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertin <lobertin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:16:49 by lobertin          #+#    #+#             */
/*   Updated: 2021/05/11 10:21:13 by lobertin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_num(t_stack *lst, int nb)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->nb == nb)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

t_stacks	a3(t_stacks stacks)
{
	int		sizea;
	int		*tab;
	int		i;
	t_stack	*buff;

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
	while (stacks.a != NULL)
	{
		buff = stacks.a;
		if (find_num(stacks.a, tab[i]) < (sizea - i) / 2)
			while (stacks.a->nb != tab[i])
				stacks = print_op("ra", ra, stacks);
		else
			while (stacks.a->nb != tab[i])
				stacks = print_op("rra", rra, stacks);
		i++;
		stacks = print_op("pb", pb, stacks);
	}
	while (stacks.b != NULL)
		stacks = print_op("pa", pa, stacks);
	return (stacks);
}
