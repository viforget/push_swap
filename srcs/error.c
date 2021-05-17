/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:04:47 by viforget          #+#    #+#             */
/*   Updated: 2021/05/17 15:39:39 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_and_exit(char *str)
{
	printf("%s", str);
	return (0);
}

void	free_and_exit(t_stacks stacks)
{
	printf("Error\n");
	free_stacks(stacks);
	exit(EXIT_FAILURE);
}
