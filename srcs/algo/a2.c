#include "push_swap.h"

t_stacks	a2(t_stacks stacks)
{
	int	i;
	int	size;

	i = 0;
	size = sizeoflist(stacks.a);
	while (!check_list(stacks.a) && i < size - 1)
	{
		if (stacks.a->nb > stacks.a->next->nb)
		{
			stacks = print_op("sa", sa, stacks);
			if (i > 0 && last_number(stacks.a) > stacks.a->nb)
			{
				i--;
				stacks = print_op("rra", rra, stacks);
			}
		}
		else
		{
			i++;
			stacks = print_op("ra", ra, stacks);
		}
	}
	stacks = print_op("ra", ra, stacks);
	return (stacks);
}
