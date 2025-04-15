/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:41:50 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/15 23:39:19 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_message(int sig)
{	
	static int	c;
	static int	bit;

	if (sig == SIGUSR1)
        c |= (1 << bit);
    bit++;
    if (bit == 8)
    {
        write(1, &c, 1);
        c = 0;
        bit = 0;
    }
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
