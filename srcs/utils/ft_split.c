/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viforget <viforget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 14:20:39 by lobertin          #+#    #+#             */
/*   Updated: 2021/05/11 17:52:33 by viforget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	word_c(const char *str, char c)
{
	int	i;
	int	nb_word;

	nb_word = 0;
	if (str[0] != c)
		nb_word++;
	i = 1;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			nb_word++;
		i++;
	}
	return (nb_word);
}

static char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*copy;

	if (!src)
		return (NULL);
	i = 0;
	copy = (char *)malloc((n + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	**split_free(char **tab, int k)
{
	while (k)
	{
		free(tab[k]);
		k--;
	}
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb[3];

	tab = (char **)malloc((word_c(s, c) + 1) * sizeof(char *));
	if (!s || !tab)
		return (0);
	nb[2] = 0;
	nb[0] = 0;
	while (s[nb[0]])
	{
		nb[1] = 0;
		while (s[nb[0] + nb[1]] && s[nb[0] + nb[1]] != c)
			nb[1]++;
		if (nb[1])
		{
			tab[nb[2]] = ft_strndup((char *)&s[nb[0]], nb[1]);
			if (!tab[nb[2]++])
				return (split_free(tab, nb[2] - 2));
			nb[0] = nb[0] + nb[1];
		}
		if (s[nb[0]])
			nb[0]++;
	}
	tab[nb[2]] = 0;
	return (tab);
}
