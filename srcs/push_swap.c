/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:04:36 by viforget          #+#    #+#             */
/*   Updated: 2021/05/12 18:34:17 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	find_algo(t_stacks stacks)
{
	int	sizea;

	sizea = sizeoflist(stacks.a);
	if (sizea > 100)
		stacks = a4(stacks);
	else if (sizea > 20)
		stacks = a1(stacks);
	else if (sizea >= 10)
		stacks = a3(stacks);
	else if (sizea > 3)
		stacks = a2(stacks);
	else if (sizea == 3)
		stacks = a_3(stacks);
	else if (sizea == 2)
		stacks = a_2(stacks);
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
	flag = get_flags(&av, &ac);
	if (flag == -1)
		return (0);
	stacks.a = get_list(ac, av);
	if (!stacks.a)
	{
		free_stacks(stacks);
		return (print_and_exit("Error\n"));
	}
	if (!check_list(stacks.a))
		//stacks = find_algo(stacks);
	stacks = a_4_5_6(stacks);
	//print_list(stacks.a, "A");
	free_stacks(stacks);
	return (1);
}
