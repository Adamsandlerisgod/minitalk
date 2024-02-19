/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:55:29 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/14 20:35:34 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_client_info(int signum, siginfo_t *info, void *yeet)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;

	if (signum == SIGUSR2)
		c |= 1 << bit_count;
	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
		{
			ft_putchar_fd('\n', 1);
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_putchar_fd(c, 1);
		c = 0;
		bit_count = 0;
	}
	(void)yeet;
}

void	signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_client_info;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
}

int	main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal_handler();
	while (1)
		pause();
	return (0);
}
