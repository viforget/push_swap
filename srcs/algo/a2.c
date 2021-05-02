#include "push_swap.h"

void a2(t_stacks stacks)
{
	int i;

	i = 0;
	while (!check_list(stacks.a))
	{
		//print_list(stacks.a, "A");
		
		if (stacks.a->nb > stacks.a->next->nb)
		{
			printf("sa\n");
			stacks = sa(stacks);
			if (i > 0)
			{
				i--;
				printf("rra\n");
				stacks = rra(stacks);
			}
		}
		else
		{
			i++;
			printf("ra\n");
			stacks = ra(stacks);
		}
	}
}