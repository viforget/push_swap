/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:36:55 by viforget          #+#    #+#             */
/*   Updated: 2021/05/17 16:48:13 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nb(char *str, t_stack *lst)
{
	long	nb;
	t_stack	*buf;
	int		i;

	buf = lst;
	nb = ft_atol(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	while (buf)
	{
		if (buf->next && nb == buf->nb)
			return (0);
		buf = buf->next;
	}
	nb = 0;
	if (str[0] == '-' && str[1] != '\0')
		nb = 1;
	while (str[nb])
	{
		if (!ft_isdigit(str[nb]) || nb > 10)
			return (0);
		nb++;
	}
	return (1);
}

int	check_list(t_stack *list)
{
	int	nb;

	while (list->next)
	{
		nb = list->nb;
		list = list->next;
		if (nb >= list->nb)
			return (0);
	}
	return (1);
}

t_stacks	do_ins(t_stacks stacks, char *ins)
{
	if (!ft_strcmp(ins, "sa"))
		stacks = sa(stacks);
	else if (!ft_strcmp(ins, "sb"))
		stacks = sb(stacks);
	else if (!ft_strcmp(ins, "ss"))
		stacks = ss(stacks);
	else if (!ft_strcmp(ins, "pa"))
		stacks = pa(stacks);
	else if (!ft_strcmp(ins, "pb"))
		stacks = pb(stacks);
	else if (!ft_strcmp(ins, "ra"))
		stacks = ra(stacks);
	else if (!ft_strcmp(ins, "rb"))
		stacks = rb(stacks);
	else if (!ft_strcmp(ins, "rr"))
		stacks = rr(stacks);
	else if (!ft_strcmp(ins, "rra"))
		stacks = rra(stacks);
	else if (!ft_strcmp(ins, "rrb"))
		stacks = rrb(stacks);
	else if (!ft_strcmp(ins, "rrr"))
		stacks = rrr(stacks);
	else
		free_and_exit(stacks);
	return (stacks);
}

int	nb_in_list(t_stack *lst, int nb)
{
	while (lst && nb-- > 0)
		lst = lst->next;
	if (!lst)
		return (0);
	return (lst->nb);
}

int	*tri(int *tab, int size)
{
	int	i;
	int	buf;

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
