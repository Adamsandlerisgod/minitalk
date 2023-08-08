/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrik <whendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:44 by whendrik          #+#    #+#             */
/*   Updated: 2023/08/08 19:19:00 by whendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	receive_client_info(int signal)
{
	int		char_value = 0;
	int		current_bit = 0;
	int		len_received = 0;
	int		i = 0;
	char	*final_str = 0;

	if (!len_received)
		receive_strlen()
}

int	main(void)
{
	int	id;

	id = (int)(getpid());
	ft_putnbr_fd(id, 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, receive_client_info);
}