/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:24:59 by viforget          #+#    #+#             */
/*   Updated: 2021/05/16 19:37:01 by viforget         ###   ########.fr       */
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
# ifndef CH
#  define CH 11
# endif


/*
** STRUCTURES
*/

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}				t_stacks;

/*
** ALGORITHM
*/

t_stacks	a1(t_stacks stacks);
t_stacks	a2(t_stacks stacks);
t_stacks	a3(t_stacks stacks);
t_stacks	a4(t_stacks stacks);
t_stacks	a_2(t_stacks stacks);
t_stacks	a_3(t_stacks s);
t_stacks	a_4_5_6(t_stacks stacks);

/*
** A4 UTILS
*/

int			rcheck_list(t_stack *list);
t_stacks	rrotate_until(t_stacks stacks, int nb);
t_stacks	rotate_until(t_stacks stacks, int nb);
int			get_a(t_stack *st, int nb);
int			hold_second(t_stack *st, int min, int max);
int			hold_first(t_stack *st, int min, int max);
int			last_number(t_stack *stack);

/*
** STACK_UTILS
*/

int			last_number(t_stack *stack);
t_stacks	loop_ps(int fd, t_stacks stacks, int flag);
t_stacks	do_ins(t_stacks stacks, char *ins);
t_stack		*get_list(int nb, char **av);
void		*free_stacks(t_stacks stacks);
int			*tri	(int *tab, int size);
int			print_list(t_stack *list, char *s);
int			check_list(t_stack *list);
int			get_flags(char ***av, int *ac);
int			sizeoflist(t_stack *list);
int			*lst_to_tab(t_stack *lst, int opt);
int			nb_in_list(t_stack *lst, int nb);

/*
** OPERATIONS
*/

t_stacks	print_op(char *str, t_stacks fc(t_stacks), t_stacks st);
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

int			ft_isdigit(int c);
int			ft_strcmp(const char *s1, const char *s2);
long		ft_atol(const char *str);
char		**ft_split(char const *s, char c);
char		*ft_strrep(char *str, char c, char r);

/*
** ERROR
*/

int			print_and_exit(char *str);
void	free_and_exit(t_stacks stacks);

#endif