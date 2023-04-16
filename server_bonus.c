/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:26:12 by aennaki           #+#    #+#             */
/*   Updated: 2023/02/28 18:13:19 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	recived_sig(int sig, siginfo_t *info, void *context)
{
	static int				i;
	static unsigned char	c;
	static int				pid;

	(void) context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		i = 0;
		c = 0;
	}
	c <<= 1;
	if (sig == SIGUSR1)
		c |= 1;
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	act;

	ft_putstr("pid server : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	act.sa_sigaction = recived_sig;
	act.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		sleep(1);
	return (0);
}
