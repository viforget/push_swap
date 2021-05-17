#include "push_swap.h"

t_stacks	b_3(t_stacks s)
{
	if (s.b->nb < s.b->next->nb && s.b->next->nb < s.b->next->next->nb)
		s = print_op("sb", sb, s);
	if (s.b->nb > s.b->next->nb && s.b->next->nb < s.b->next->next->nb)
		s = print_op("rrb", rrb, s);
	if (s.b->next->nb > s.b->nb && s.b->nb > s.b->next->next->nb)
		s = print_op("sb", sb, s);
	if (s.b->next->nb > s.b->nb && s.b->nb < s.b->next->next->nb)
		s = print_op("rb", rb, s);
	return (s);
}

t_stacks	rr_and_p(t_stacks stacks)
{
	stacks = print_op("rra", rra, stacks);
	stacks = print_op("pb", pb, stacks);
	return (stacks);
}

t_stacks	a_4_5_6(t_stacks stacks)
{
	int		*tab;
	int		sizea;
	t_stack	*buff;

	sizea = sizeoflist(stacks.a);
	tab = lst_to_tab(stacks.a, 1);
	while (sizeoflist(stacks.a) > 3)
	{
		if (stacks.a->nb < tab[sizea - 3])
			stacks = print_op("pb", pb, stacks);
		if (last_number(stacks.a) < tab[sizea - 3])
			stacks = rr_and_p(stacks);
		if (sizeoflist(stacks.a) > 3)
			stacks = print_op("ra", ra, stacks);
	}
	stacks = a_3(stacks);
	if (sizeoflist(stacks.b) == 3)
		stacks = b_3(stacks);
	else if (sizeoflist(stacks.b) == 2 && stacks.b->nb < stacks.b->next->nb)
		stacks = print_op("sb", sb, stacks);
	while (stacks.b)
		stacks = print_op("pa", pa, stacks);
	return (stacks);
}
