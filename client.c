/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:25:39 by aennaki           #+#    #+#             */
/*   Updated: 2023/04/01 16:58:12 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*char_to_bin(char c)
{
	int	*bin;
	int	i;

	bin = (int *) malloc(sizeof(int) * 8);
	if (!bin)
		return (0);
	i = 8;
	while (--i >= 0)
	{
		bin[i] = c % 2;
		c /= 2;
	}
	return (0);
}

void	send_bin(char *str, int pidserv)
{
	int	i;
	int	div;
	int	*bin;

	i = -1;
	while (++i <= ft_strlen(str))
	{
		bin = char_to_bin(str[i]);
		div = -1;
		while (++div < 8)
		{
			if (bin[div])
				kill(pidserv, SIGUSR1);
			else
				kill(pidserv, SIGUSR2);
			usleep(500);
		}
		free(bin);
	}
}

int	main(int ac, char **av)
{
	int	pidserv;
	int	i;

	i = 1;
	pidserv = ft_atoi(av[1]);
	if (ac != 3 || pidserv <= 0)
		ft_putstr("Wrong infos! Try again.");
	else
		send_bin(av[2], pidserv);
	return (0);
}
