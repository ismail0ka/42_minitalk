/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:57:21 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/16 05:44:22 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_data(int pid, unsigned char c)
{
	int	bit;

	bit = 8;
	while (bit)
	{
		if ((c >> --bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
	}
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
	while (message[++i])
		send_data(pid, (unsigned char)message[i]);
	return (0);
}
