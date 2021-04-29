/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:24:59 by viforget          #+#    #+#             */
/*   Updated: 2021/04/28 18:55:50 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*
** INCLUDE
*/

#include <stdlib.h>
#include <stdio.h>

#include "get_next_line.h"

/*
** DEFINE
*/

# define A 0
# define B 1
//# define LONG_MAX 9223372036854775807

/*
** STRUCTURES
*/

typedef struct	s_stack
{
	int			nb;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_stacks
{
	t_stack	*a;
	t_stack	*b;
}				t_stacks;

/*
** OPERATIONS
*/


t_stacks	sa(t_stacks stacks);
t_stacks	sb(t_stacks stacks);
t_stacks	ss(t_stacks stacks);
t_stacks	pa(t_stacks stacks);
t_stacks	pb(t_stacks stacks);
t_stacks	ra(t_stacks stacks);
t_stacks	rb(t_stacks stacks);
t_stacks	rr(t_stacks stacks);
t_stacks	rra(t_stacks stacks);
t_stacks	rrb(t_stacks stacks);
t_stacks	rrr(t_stacks stacks);

/*
** LIB FUNCTIONS
*/

int     ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);

#endif