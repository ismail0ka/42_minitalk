/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:57:21 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/15 23:33:17 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, const char **av)
{
	int		pid;
	char	*message;
	int		i;
	int		bit;

	if (ac != 3)
	{
		write(2, "Usage: ./client <PID> <message>\n", 33);
		exit(EXIT_FAILURE);
	}
	pid = atoi(av[1]);
	if (pid <= 0)
	{
		write(2, "Invalid PID\n", 12);
		exit(EXIT_FAILURE);
	}
	message = (char *)av[2];
	i = 0;
	while (message[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if ((message[i] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bit++;
			usleep(600);
		}
		i++;
	}
	kill(pid, SIGUSR1);
	return (0);
}
