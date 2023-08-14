/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:32 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/14 18:52:37 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	input_errorcheck(int ac, char **argv)
{
	int	i;

	i = 0;
	if (ac != 3)
		return (0);
	while (argv[1][i])
	{
		if (!(argv[1][i] >= '0' && argv[1][i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	send_str_to_serv(unsigned char c, pid_t pid)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		usleep(WAIT_TIME);
	}
}

int	main(int ac, char **argv)
{
	pid_t	pid;
	char	*str;
	int		len;
	int		i;

	if (input_errorcheck(ac, argv) == 0)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	str = argv[2];
	len = ft_strlen(str);
	i = 0;
	while (len != i)
		send_str_to_serv(str[i++], pid);
	send_str_to_serv('\0', pid);
}
