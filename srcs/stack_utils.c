/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:36:55 by viforget          #+#    #+#             */
/*   Updated: 2021/05/02 06:27:50 by viforget         ###   ########.fr       */
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

int		check_nb(char *str, t_stack *lst)
{
	int		nb;
	t_stack	*buf;

	buf = lst;
	nb = ft_atoi(str);
	while(buf->next)
	{
		if (nb == buf->nb)
			return (0);
		buf = buf->next;
	}
	printf("NUZE\n");
	nb = 0;
	if (str[0] == '-' && str[1] != '\0')
		nb = 1;
	while (str[nb])
	{
		if (!ft_isdigit(str[nb]))
			return (0);
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
	i = 1;
	while (i < nb)
	{
		if (!check_nb(av[i], lst))
			printf("T'es NUL\n");
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