#include "push_swap.h"

void	pa(t_stack *stack[2])
{
	t_stack *buf;

	buf = stack[B];
	stack[B] = stack[B]->next;
	buf->next = stack[A];
	stack[A] = buf;
}

void	pb(t_stack *stack[2])
{
	t_stack *buf;

	buf = stack[A];
	stack[A] = stack[A]->next;
	buf->next = stack[B];
	stack[B] = buf;
}