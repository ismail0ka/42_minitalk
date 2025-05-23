/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarouat <ikarouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 03:41:50 by ikarouat          #+#    #+#             */
/*   Updated: 2025/04/17 22:31:06 by ikarouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_message(int sig, siginfo_t *info, void *context)
{
	static unsigned char	curr_c;
	static int				bit;
	static int				reg_pid;

	(void)context;
	if (reg_pid != info->si_pid)
	{
		if (reg_pid != 0)
		{
			curr_c = 0;
			bit = 0;
		}
		reg_pid = info->si_pid;
	}
	curr_c = (curr_c << 1) | (sig == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		write(1, &curr_c, 1);
		bit = 0;
		curr_c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server started\nPID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &get_message;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
