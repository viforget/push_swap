/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:36:55 by viforget          #+#    #+#             */
/*   Updated: 2021/05/14 18:11:39 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <stdlib.h>

int	print_list(t_stack *list, char *s)
{
	printf("%s :", s);
	while (list)
	{
		printf("%d ", list->nb);
		list = list->next;
	}
	printf("\n");
	return (1);
}

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

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

t_stack	*get_list(int nb, char **av)
{
	t_stack	*lst;
	t_stack	*buf;
	int		i;
	int		j;
	char 	**tab;

	lst = malloc(sizeof(t_stack));
	lst->next = NULL;
	buf = lst;
	i = 0;
	while(i < nb)
	{
		av[i] = ft_strrep(av[i], '\t', ' ');
		tab = ft_split(av[i], ' ');
		j = 0;
		while (tab[j])
		{
			if (!check_nb(tab[j], lst))
				return (NULL);
			buf->nb = ft_atol(tab[j]);
			if (i + 1 < nb || tab[j + 1])
			{
				buf->next = malloc(sizeof(t_stack));
				buf->next->next = NULL;
			}
			else
				buf->next = NULL;
			buf = buf->next;
			j++;
		}
		free_tab(tab);
		i++;
	}
	return (lst);
}

/*t_stack	*get_list(int nb, char **av)
{
	t_stack	*lst;
	t_stack	*buf;
	int		i;

	lst = malloc(sizeof(t_stack));
	lst->next = NULL;
	buf = lst;
	i = 0;
	while (i < nb)
	{
		if (!check_nb(av[i], lst))
			return (NULL);
		buf->nb = ft_atol(av[i]);
		i++;
		if (i < nb)
		{
			buf->next = malloc(sizeof(t_stack));
			buf->next->next = NULL;
		}
		else
			buf->next = NULL;
		buf = buf->next;
	}
	return (lst);
}*/


int	*lst_to_tab(t_stack *lst, int opt)
{
	int *tab;
	int size;
	int i;

	i = 0;
	size = sizeoflist(lst);
	tab = malloc(sizeof(int)* size);
	while(lst->next)
	{
		tab[i] = lst->nb;
		lst = lst->next;
		i++;
	}
	if (opt == 1)
		tab = tri(tab, size);
	return (tab);
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

int	get_flags(char ***av, int *ac)
{
	int	flag;
	int exit;

	exit = 0;
	flag = 0;
	(*ac)--;
	av[0]++;
	while (*ac && (*av)[0][0] == '-' && exit == 0)
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
			exit = 1;
	}
	return (flag);
}

t_stacks	loop_ps(int fd, t_stacks stacks, int flag)
{
	char	*str;

	while (get_next_line(fd, &str))
	{
		stacks = do_ins(stacks, str);
		if (flag % 2 == 1)
		{
			print_list(stacks.a, "A");
			print_list(stacks.b, "B");
			printf("\n");
		}
		free(str);
	}
	return (stacks);
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

int	sizeoflist(t_stack *list)
{
	if (list == NULL)
		return (0);
	else
		return (sizeoflist(list->next) + 1);
}

int	nb_in_list(t_stack *lst, int nb)
{
	while (lst && nb-- > 0)
		lst = lst->next;
	if (!lst)
		return (0);
	return (lst->nb);
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

int *tri(int *tab, int size)
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
