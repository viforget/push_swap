/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:36:55 by viforget          #+#    #+#             */
/*   Updated: 2021/05/05 14:47:02 by viforget         ###   ########.fr       */
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

int		check_nb(char *str, t_stack *lst)
{
	int		nb;
	t_stack	*buf;

	buf = lst;
	nb = ft_atoi(str);
	while(buf)
	{
		if (buf->next && nb == buf->nb)
			return(0);
		buf = buf->next;
	}
	nb = 0;
	if (str[0] == '-' && str[1] != '\0')
		nb = 1;
	while (str[nb])
	{
		if (!ft_isdigit(str[nb]))
			return(print_and_exit("CHAR"));
		nb++;
	}
	return (1);
}

t_stack	*get_list(int nb, char **av)
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
		buf->nb = ft_atoi(av[i]);
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

int get_flags(char ***av, int *ac)
{
	int flag;

	flag = 0;
	(*ac)--;
	av[0]++;
	while(*ac && (*av)[0][0] == '-')
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
	if (!ft_strcmp(ins, "sb"))
		stacks = sb(stacks);
	if (!ft_strcmp(ins, "ss"))
		stacks = ss(stacks);
	if (!ft_strcmp(ins, "pa"))
		stacks = pa(stacks);
	if (!ft_strcmp(ins, "pb"))
		stacks = pb(stacks);
	if (!ft_strcmp(ins, "ra"))
		stacks = ra(stacks);
	if (!ft_strcmp(ins, "rb"))
		stacks = rb(stacks);
	if (!ft_strcmp(ins, "rr"))
		stacks = rr(stacks);
	if (!ft_strcmp(ins, "rra"))
		stacks = rra(stacks);
	if (!ft_strcmp(ins, "rrb"))
		stacks = rrb(stacks);
	if (!ft_strcmp(ins, "rrr"))
		stacks = rrr(stacks);
	return (stacks);
}

int sizeoflist(t_stack *list)
{
	if (list == NULL)
		return(0);
	else
		return(sizeoflist(list->next) + 1);
}

void	*free_stacks(t_stacks stacks)
{

	t_stack *buf;

	while(stacks.a)
	{
		buf = stacks.a;
		stacks.a = stacks.a->next;
		free(buf);
	}
	while(stacks.b)
	{
		buf = stacks.b;
		stacks.b = stacks.b->next;
		free(buf);
	}
	return (NULL);
}

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