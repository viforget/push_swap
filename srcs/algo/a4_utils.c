#include "push_swap.h"

int	get_a(t_stack *st, int nb)
{
	int	cnt;
	int	a[2];
	int	nbr;

	cnt = 1;
	a[0] = -1;
	a[1] = 0;
	if (!st)
		return (0);
	nbr = st->nb;
	while (st && st->next)
	{
		cnt++;
		if (st->nb < st->next->nb)
			a[1] = cnt - 1;
		if (nb < st->nb && nb > st->next->nb)
			a[0] = cnt - 1;
		st = st->next;
	}
	if (nb < st->nb && nb > nbr)
		a[0] = 0;
	if (a[0] == -1)
		return (a[1]);
	return (a[0]);
}

int	hold_second(t_stack *st, int min, int max)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (st)
	{
		if (st->nb >= min && st->nb < max)
			x = i;
		i++;
		st = st->next;
	}
	return (i - x);
}

int	hold_first(t_stack *st, int min, int max)
{
	int	x;

	x = 0;
	while (st && (st->nb < min || st->nb > max))
	{
		x++;
		st = st->next;
	}
	return (x);
}

int	last_number(t_stack *stack)
{
	if (!stack->next)
		return (stack->nb);
	return (last_number(stack->next));
}
