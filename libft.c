/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:39:14 by aennaki           #+#    #+#             */
/*   Updated: 2023/04/01 15:49:03 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_putnbr(int nbr)
{
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + 48);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	if (!str)
		return (-1);
	i = 0;
	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		if (res > INT_MAX || str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	if (str[i])
		return (-1);
	return (res);
}
