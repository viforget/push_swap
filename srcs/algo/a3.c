/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a3.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 18:12:05 by lobertin          #+#    #+#             */
/*   Updated: 2021/05/02 06:03:04 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*tri	(int *tab, int size)
{
	int i;
	int buf;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			buf = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = buf;
			if (i > 0)
				i--;
		}
		else
			i++;
	}
	return (tab);
}

int sizeoflist(t_stack *list)
{
	if (list == NULL)
		return(0);
	else
		return(sizeoflist(list->next) + 1);
}

int	find_num(t_stack *lst, int nb)
{
	int i;

	i = 0;
	while(lst)
	{
		if (lst->nb == nb)
			return(i);
		i++;
		lst = lst->next;
	}
	return (-1);
}

void a3(t_stacks stacks)
{
	int sizea;
	int *tab;
	int i;
	t_stack *buff;
	
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
			{
				printf("ra\n");
				stacks = ra(stacks);
			}
		else	
			while (stacks.a->nb != tab[i])
			{
				printf("rra\n");
				stacks = rra(stacks);
			}
		i++;
		printf("pb\n");
		stacks = pb(stacks);
	}
	while (stacks.b != NULL)
	{
		printf("pa\n");
		stacks = pa(stacks);
	}
}
    