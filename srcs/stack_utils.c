/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:36:55 by viforget          #+#    #+#             */
/*   Updated: 2021/05/01 22:21:31 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*get_list(int nb, char **av)
{
	t_stack	*lst;
	t_stack	*buf;
	int		i;

	lst = malloc(sizeof(t_stack));
	buf = lst;
	i = 1;
	while (i < nb)
	{
		buf->nb = ft_atoi(av[i]);
		i++;
		if (i < nb)
			buf->next = malloc(sizeof(t_stack));
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
		}
		free(str);
	}
	return (stacks);
}
