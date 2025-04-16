/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:41:50 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/16 05:44:16 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*void	send_ack(int client_pid)
{
	if (kill(client_pid, SIGUSR1) == -1)
	{
		ft_printf("Failed to send ACK to client %d\n", client_pid);
		exit(EXIT_FAILURE);
	}
}*/

void	get_message(int sig)
{
	static unsigned char	curr_c;
	static int				bit;

	curr_c = (curr_c << 1) | (sig == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		write(1, &curr_c, 1);	
		bit = 0;
		curr_c = 0;
	}
}

int	main(void)
{
	ft_printf("Server started\nPID: %d\n", getpid());
	signal(SIGUSR1, get_message);
	signal(SIGUSR2, get_message);
	while (1)
		;
	return (0);
}
