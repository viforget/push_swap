/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertin <lobertin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:23:46 by viforget          #+#    #+#             */
/*   Updated: 2021/05/11 10:36:48 by lobertin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	print_op(char *str, t_stacks fc(t_stacks), t_stacks st)
{
	printf("%s\n", str);
	return (fc(st));
}
