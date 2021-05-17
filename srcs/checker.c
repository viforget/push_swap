/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:36:55 by viforget          #+#    #+#             */
/*   Updated: 2021/05/17 15:40:02 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;
	char		*str;
	int			flag;

	flag = 0;
	if (ac <= 1)
		return (1);
	flag = get_flags(&av, &ac);
	stacks.a = get_list(ac, av);
	if (!stacks.a)
		return (print_and_exit("Error\n"));
	if (read(0, NULL, 0) == 0)
		stacks = loop_ps(0, stacks, flag);
	else
		stacks = loop_ps(1, stacks, flag);
	if (check_list(stacks.a) && stacks.b == NULL)
		printf("OK\n");
	else
		printf("KO\n");
	free_stacks(stacks);
	return (1);
}
