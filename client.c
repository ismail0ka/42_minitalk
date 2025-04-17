/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:57:21 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/17 17:51:14 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_ack(int sig)
{
	(void)sig;
	ft_printf("Server received a bit\n");
}

void	send_bit(int pid, int bit)
{ 
	if (bit)
		kill(pid, SIGUSR1);//1
	else
		kill(pid, SIGUSR2);//0
	pause();
}

void	send_data(int pid, unsigned char c)
{
	int	bit;

	bit = 8;
	while (bit)
		send_bit(pid, (c >> --bit) & 1);
}

void	msg_ack(int sig)
{
	(void)sig;
	ft_printf("Server received the message\n");
}

int	main(int ac, const char **av)
{
	int		pid;
	char	*message;
	int		i;

	if (ac != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 33);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(2, "Invalid PID\n", 12);
		exit(EXIT_FAILURE);
	}
	message = (char *)av[2];
	i = -1;
	signal(SIGUSR1, sig_ack);
	while (message[++i])
		send_data(pid, (unsigned char)message[i]);
	send_data(pid, 0);
	return (0);
}
