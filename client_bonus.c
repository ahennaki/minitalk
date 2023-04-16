/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:26:47 by aennaki           #+#    #+#             */
/*   Updated: 2023/04/01 16:57:51 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*char_to_bin(unsigned char c)
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
	return (bin);
}

void	send_bin(unsigned char *str, int pidserv)
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

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("signal received\n");
}

int	main(int ac, char **av)
{
	int	pidserv;
	int	i;

	signal(SIGUSR1, signal_handler);
	usleep(500);
	i = 1;
	pidserv = ft_atoi(av[1]);
	if (ac != 3 || pidserv <= 0)
		ft_putstr("Wrong infos! Try again.");
	else
		send_bin((unsigned char *)av[2], pidserv);
	return (0);
}
