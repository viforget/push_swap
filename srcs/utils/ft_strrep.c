#include "push_swap.h"

char	*ft_strrep(char *str, char c, char r)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			str[i] = r;
		i++;
	}
	return (str);
}