#include "push_swap.h"

int	find_num(t_stack *lst, int nb);
int	sizeoflist(t_stack *list);
int	*tri	(int *tab, int size);

t_stacks	coupe (t_stacks stacks, int size, int *tab, int max)
{
	int		i;
	t_stack	*buff;	

	i = -1;
	buff = stacks.a;
	while (i < size * 2)
	{
		if (stacks.a->nb < tab[max - size])
			stacks = print_op("pb", pb, stacks);
		else
			stacks = print_op("ra", ra, stacks);
	}
	if (size > 1)
		stacks = coupe(stacks, size / 2, tab, max);
	return (stacks);
}

t_stacks	retour (t_stacks stacks, int *tab, int size)
{
	int	i;

	i = 2;
	while (size > i)
	{
		if (find_num(stacks.b, tab[size - i]) < (size - i) / 2)
			while (stacks.b->nb != tab[size - i])
				stacks = print_op("rb", rb, stacks);
		else
			while (stacks.b->nb != tab[size - i])
				stacks = print_op("rrb", rrb, stacks);
		i++;
		stacks = print_op("pa", pa, stacks);
	}
	return (stacks);
}

t_stacks	a1(t_stacks stacks)
{
	int		sizea;
	int		*tab;
	int		i;
	t_stack	*buff;

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
	stacks = coupe(stacks, sizea / 2, tab, sizea);
	stacks = retour(stacks, tab, sizea);
	stacks = print_op("pa", pa, stacks);
	return (stacks);
}
