#include "push_swap.h"

t_stack	*get_list(int nb, char **av);

int main(int ac, char **av)
{
	t_stacks	stacks;
	char		*str;
	int			flag;

	flag = 0;
	if (ac <= 1)
		return (1);
	while (av[1] && av[1][0] == '-')
	{
		if (!ft_strcmp("-v", av[1]))
			flag += 1;
		if (!ft_strcmp("-c", av[1]))
			flag += 2;
		av++;
		ac--;
	}

	stacks.a = get_list(ac, av);
	a3(stacks);
}