#include "push_swap.h"

int	rcheck_list(t_stack *list)
{
	int	nb;

	while (list->next)
	{
		nb = list->nb;
		list = list->next;
		if (nb <= list->nb)
			return (0);
	}
	return (1);
}

t_stacks	rrotate_until(t_stacks stacks, int nb)
{
	while (nb-- > 0)
		stacks = print_op("rrb", rrb, stacks);
	return (stacks);
}

t_stacks	rotate_until(t_stacks stacks, int nb)
{
	while (nb-- > 0)
		stacks = print_op("rb", rb, stacks);
	return (stacks);
}
