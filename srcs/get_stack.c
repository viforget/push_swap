/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:36:55 by viforget          #+#    #+#             */
/*   Updated: 2021/05/18 10:25:35 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_list_loop(char **tab, t_stack *lst, t_stack *buf, int c)
{
	int	j;

	j = 0;
	while (tab[j])
	{
		if (!check_nb(tab[j], lst))
		{
			free_stack(lst);
			return (free_tab(tab));
		}
		buf->nb = ft_atol(tab[j]);
		if (c || tab[j + 1])
		{
			buf->next = malloc(sizeof(t_stack));
			buf->next->next = NULL;
			buf = buf->next;
		}
		else
			buf->next = NULL;
		j++;
	}
	free_tab(tab);
	return (buf);
}

t_stack	*get_list(int nb, char **av)
{
	t_stack	*lst;
	t_stack	*buf;
	int		i;
	int		j;
	char	**tab;

	lst = malloc(sizeof(t_stack));
	lst->next = NULL;
	buf = lst;
	i = 0;
	while (i < nb)
	{
		tab = ft_split(ft_strrep(av[i], '\t', ' '), ' ');
		buf = get_list_loop(tab, lst, buf, i + 1 < nb);
		if (!buf)
			return (NULL);
		i++;
	}
	return (lst);
}

int	*lst_to_tab(t_stack *lst, int opt)
{
	int	*tab;
	int	size;
	int	i;

	i = 0;
	size = sizeoflist(lst);
	tab = malloc(sizeof(int)* size);
	while (lst)
	{
		tab[i] = lst->nb;
		lst = lst->next;
		i++;
	}
	if (opt == 1)
		tab = tri(tab, size);
	return (tab);
}

int	get_flags(char ***av, int *ac)
{
	int	flag;

	flag = 0;
	(*ac)--;
	av[0]++;
	while (*ac && (*av)[0][0] == '-')
	{
		if (!ft_strcmp("-v", (*av)[0]))
			flag += 1;
		else if (!ft_strcmp("-c", (*av)[0]))
			flag += 2;
		else if (!ft_isdigit((*av)[0][1]))
			return (-1);
		if (!ft_isdigit((*av)[0][1]))
		{
			(*ac)--;
			av[0]++;
		}
		else
			return (-1);
	}
	return (flag);
}

int	sizeoflist(t_stack *list)
{
	if (list == NULL)
		return (0);
	else
		return (sizeoflist(list->next) + 1);
}
