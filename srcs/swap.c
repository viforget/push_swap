#include "push_swap.c"

void	sa(t_stack *stack[2])
{
	int nb;

	nb = stack[A]->nb;
	stack[A]->nb = stack[A]->next->nb;
	stack[A]->next->nb = nb
}

void	sb(t_stack *stack[2])
{
	int nb;

	nb = stack[B]->nb;
	stack[B]->nb = stack[B]->next->nb;
	stack[B]->next->nb = nb
}

void	ss(t_stack *stack[2])
{
	sa(stack);
	sb(stack);
}