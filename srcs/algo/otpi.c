#include "push_swap.h"

void opti(t_stacks stacks, int *tab, int sizea, int i)
{
	int hold_first[2];
	int hold_second[2];
	int x;
	int y[3];
	int z[2];
	int sizeb;

	while (stacks.a < tab[sizea / 11 * i] && stacks.a > tab[sizea / 11 * i + 1])
	{
		x++;
		stacks.a = stacks.a->next;
	}
	hold_first[0] = x;
	hold_first[1] = stacks.a -> nb;
	x = 0;
	while (stacks.a)
	{
		if (stacks.a < tab[sizea / 11 * i] && stacks.a > tab[sizea / 11 * i + 1])
		{
			hold_second[0] = x;
			hold_second[1] = stacks.a -> nb;
		}
		x++;
		stacks.a = stacks.a->next;
	}
	if (hold_first[0] < sizea - hold_second[0])
	{
		y[0] = hold_first[0] //index
		y[1] = hold_first[1] //valeur
		y[2] = 1;			 //ra
	}
	else
	{
		y[0] = hold_second[0] //index
		y[1] = hold_second[1] //valeur
		y[2] = 2;			  //rra
	}
	sizeb = sizeoflist(stacks.b);
	while (stacks.b)
	{
		if(!(y[1] < stacks.b -> nb && y[1] > stacks.b->next->nb))
			stacks.b = stacks.b -> next;
		else
		{
			z[0] = x //index
			if (x < sizeb / 2)
			{
				z[1] = 1 //rb
			}
			else
			{
				z[1] = 2 //rrb
			}		
		}
		x++;
	}
	if (y[2] == z[1])
	{
		if (y[2] == 1)
		{
			if (y[0] < z[0])
			{
				while (y[0]--)
					stacks = print_op("rr", rr, stacks);
				z[0] = z[0] - y[0];
				while (z[0]--)
					stacks = print_op("rb", rb, stacks);
			}
			else
			{
				while (z[0]--)
					stacks = print_op("rr", rr, stacks);
				y[0] = y[0] - z[0];
				while (y[0]--)
					stacks = print_op("ra", ra, stacks);
			}
		}
		else
		{
			if (y[0] < z[0])
			{
				while (y[0]--)
					stacks = print_op("rrr", rrr, stacks);
				z[0] = z[0] - y[0];
				while (z[0]--)
					stacks = print_op("rrb", rrb, stacks);
			}
			else
			{
				while (z[0]--)
					stacks = print_op("rrr", rrr, stacks);
				y[0] = y[0] - z[0];
				while (y[0]--)
					stacks = print_op("rra", rra, stacks);
			}
		}
	}
	else
	{
		if (y[2] == 1)
			while (y[0]--)
				stacks = print_op("ra", ra, stacks);
		else
			while (y[0]--)
				stacks = print_op("rra", rra, stacks);
		if (z[1] == 1)
			while (z[0]--)
				stacks = print_op("rb", rb, stacks);
		else
			while (z[0]--)
				stacks = print_op("rrb", rrb, stacks);
	}
	stacks = print_op("pb", pb, stacks);
}