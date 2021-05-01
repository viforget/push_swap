/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:36:55 by viforget          #+#    #+#             */
/*   Updated: 2021/05/01 22:21:30 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int			flag;

	flag = 0;
	if (ac <= 1)
		return (1);
	while (av[1] && av[1][0] == '-')
	{
		if (!ft_strcmp("-v", av[1]))
			flag += 1;
		if (!ft_strcmp("-c", av[1]))
			flag += 2;
		av++;
		ac--;
	}
	//printf("%s\n", av[1]);
	stacks.a = get_list(ac, av);
	if (read(0, NULL, 0) == 0)
		stacks = loop_ps(0, stacks, flag);
	else
		stacks = loop_ps(1, stacks, flag);
	if (check_list(stacks.a) && stacks.b == NULL)
		printf("OK\n");
	else
		printf("KO\n");
	return (1);
}
