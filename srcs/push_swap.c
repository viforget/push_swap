/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:04:36 by viforget          #+#    #+#             */
/*   Updated: 2021/05/05 14:46:20 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stacks	stacks;
	char		*str;
	int			flag;

	flag = 0;
	if (ac <= 1)
		return (1);
	flag = get_flags(&av, &ac);
	if (flag == -1)
		return (0);
	stacks.a = get_list(ac, av);
	if (!stacks.a)
		return(print_and_exit("Error\n"));
	if (!check_list(stacks.a))
		stacks = a4(stacks);
	free_stacks(stacks);
}