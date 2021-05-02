#include "push_swap.h"

int sizeoflist(t_stack *list);

void a2(t_stacks stacks)
{
	int i;
	int size;

	i = 0;
	size = sizeoflist(stacks.a);
	while (!check_list(stacks.a) && i < size - 1)
	{
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
	//print_list(stacks.a, "A");
	printf("ra\n");
	stacks = ra(stacks);
}