#include "push_swap.h"

void	ra(t_stack *stack[2])
{
	t_stack *buf;
	t_stack *buf2;

	buf = stack[A];
	buf2 = buf;
	stack[A] = stack[A]->next;
	while(buf2->next)
		buf2 = buf2->next;
	buf2->next = buf;
	buf->next = NULL;		
}

void	rb(t_stack *stack[2])
{
	t_stack *buf;
	t_stack *buf2;

	buf = stack[B];
	buf2 = buf;
	stack[B] = stack[B]->next;
	while(buf2->next)
		buf2 = buf2->next;
	buf2->next = buf;
	buf->next = NULL;		
}

void	rr(t_stack *stack[2])
{
	ra(stack);
	rb(stack);
}