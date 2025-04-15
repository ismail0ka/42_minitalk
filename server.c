/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:41:50 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/15 04:12:25 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_message(void)
{
	static int		i = 0;
	static char		c = 0;
	static int		bit = 0;

	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
	if (i == 1)
	{
		c |= (1 << bit);
	}
	else
	{
		c &= ~(1 << bit);
	}
	bit++;
	i = (i + 1) % 2;
}

int	main(void)
{
	ft_printf("Server started\nPID: %d\n", getpid());
	signal(SIGUSR1, get_message);
	signal(SIGUSR2, get_message);
	while (1)
	{
		pause();
	}
	return (0);
}
