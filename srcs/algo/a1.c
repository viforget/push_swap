#include "push_swap.h"

int	find_num(t_stack *lst, int nb);
int sizeoflist(t_stack *list);
int	*tri	(int *tab, int size);

t_stacks coupe (t_stacks stacks, int size, int *tab, int max)
{
	int i;
	i = -1;
	t_stack *buff;
	
	buff = stacks.a;
	while(i < size*2)
	{
		if (stacks.a->nb < tab[max - size])
		{
			printf("pb\n");
			stacks = pb(stacks);
//			print_list(stacks.a,"A");
//			print_list(stacks.b,"B");
		}
		else
		{
			printf("ra\n");
			stacks = ra(stacks);
//			print_list(stacks.a,"A");
//			print_list(stacks.b,"B");
			i++;
		}
	}
	if (size > 1)
	{
//		printf("test\n\n\n");
		stacks = coupe(stacks, size/2, tab, max);
	}
	return(stacks);
}

t_stacks retour (t_stacks stacks, int *tab, int size)
{
	int i;

	i = 2;
	while (size > i)
	{
		if (find_num(stacks.b, tab[size-i]) < (size - i) / 2)
			while (stacks.b->nb != tab[size-i])
			{	
				printf("rb\n");
				stacks = rb(stacks);
//				print_list(stacks.a,"A");
//				print_list(stacks.b,"B");
			}
		else
			while (stacks.b->nb != tab[size-i])
			{
				printf("rrb\n");
				stacks = rrb(stacks);
//				print_list(stacks.a,"A");
//				print_list(stacks.b,"B");
			}
		i++;
		printf("pa\n");
		stacks = pa(stacks);
	}
	return(stacks);
}

void a1(t_stacks stacks)
{
	int sizea;
	int *tab;
	int i;
	t_stack *buff;

	sizea = sizeoflist(stacks.a);
	tab = malloc(sizeof(int)* sizea);
	i = 0;
	buff = stacks.a;
	while (buff != NULL)
	{
		tab[i++] = buff->nb;
		buff = buff->next;
	}
	tab = tri(tab, sizea);
    stacks = coupe(stacks, sizea/2, tab, sizea);
	stacks = retour(stacks, tab, sizea);
	printf("pa\n");
	stacks = pa(stacks);
	//print_list(stacks.a,"A");
	//print_list(stacks.b,"B");
}
