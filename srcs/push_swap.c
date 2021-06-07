/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:04:36 by viforget          #+#    #+#             */
/*   Updated: 2021/05/18 10:31:04 by viforget         ###   ########.fr       */
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
	else if (sizea > 6)
		stacks = a2(stacks);
	else if (sizea > 3)
		stacks = a_4_5_6(stacks);
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

	if (ac <= 1)
		return (1);
	stacks.a = get_list(ac - 1, av + 1);
	if (!stacks.a)
	{
		free_stacks(stacks);
		return (print_and_exit("Error\n"));
	}
	if (!check_list(stacks.a))
		stacks = find_algo(stacks);
	return (1);
}
