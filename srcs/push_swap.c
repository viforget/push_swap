/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:04:36 by viforget          #+#    #+#             */
/*   Updated: 2021/05/03 14:19:27 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return(0); //Doublons
	if (!check_list(stacks.a))
		a1(stacks);
}