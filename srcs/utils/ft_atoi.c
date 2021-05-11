/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertin <lobertin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:11:43 by viforget          #+#    #+#             */
/*   Updated: 2021/05/11 10:32:27 by lobertin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int					x;
	unsigned long long	n_final;
	int					negatif;

	n_final = 0;
	negatif = 1;
	x = 0;
	while ((str[x] <= 9 && str[x] >= 13 ) || str[x] == ' ')
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x++] == '-')
			negatif = negatif * -1;
	}
	while (str[x] <= '9' && str[x] >= '0' && str[x])
	{
		n_final = n_final * 10 + (str[x++] - 48);
		if (n_final > 2147483648)
			return (((negatif - 1) * -1) / 2);
	}
	n_final = n_final * negatif;
	return ((int)n_final);
}
