/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:32 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/08 18:36:58 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	input_errorcheck(int ac, char **argv)
{
	int	i;

	i = 0;
	if (ac != 3)
		return (0);
	while (argv[1][i])
	{
		if (!(ft_isdigit(argv[1][i])))
			return (0);
		i++;
	}
}

void	send_strlen(int len, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (len & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		len = len >> 1;	
		usleep(600);
		i++;
	}
}

void	send_str_to_serv(unsigned char c, pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c >> 1;
		usleep(600);
		i++;
	}
}

int	main(int ac, char **argv)
{
	pid_t	pid;
	char	*str;

	if (input_errorcheck(ac, argv) == 0)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (0);
	str = argv[2];
	send_strlen(ft_strlen(str), pid);
	while (*str)
	{
		send_str_to_serv(*str, pid);
		(*str)++;
	}
}