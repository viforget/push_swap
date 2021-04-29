/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:36:55 by viforget          #+#    #+#             */
/*   Updated: 2021/04/29 14:05:12 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int 	print_list(t_stack *list)
{
	while (list)
	{
		printf("%d ", list->nb);
		list = list->next;
	}
	printf("\n");
	return (1);
}
*/

t_stack	*get_list(int nb, char **av)
{
	t_stack	*lst;
	t_stack	*buf;
	int		i;

	lst = malloc(sizeof(t_stack));
	buf = lst;
	i = 1;
	while(i < nb)
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

int 	check_list(t_stack *list)
{
	int nb;

	nb = list->nb;
	while (list->next)
	{
		list = list->next;
		if (nb < list->nb)
			return(0);
	}
	return (1);
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

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*str;

	stacks.a = get_list(ac, av);
	while(get_next_line(1, &str))
	{
		print_list(stacks.a);
		stacks = do_ins(stacks, str);
		print_list(stacks.a);
		free(str);
	}
	if(check_list(stacks.a) && stacks.b == NULL)
		printf("OK\n");
	else
		printf("KO\n");
	
}