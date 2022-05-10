/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 23:12:48 by hchahid           #+#    #+#             */
/*   Updated: 2022/03/18 16:38:46 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_tmp;

void	reset(char *printed, int *shifter, int pid)
{
	*printed = 0;
	*shifter = 0;
	g_tmp = pid;
}

void	sighandle(int sig, siginfo_t *siginfo, void *context)
{
	static char	printed;
	static int	shifter;

	(void) context;
	if (g_tmp != siginfo->si_pid)
		reset(&printed, &shifter, siginfo->si_pid);
	if (sig == SIGUSR1)
		printed = printed << 1;
	else if (sig == SIGUSR2)
		printed = (printed << 1) + 1;
	shifter++;
	if (shifter == 8)
	{
		write(1, &printed, 1);
		if (printed == 0)
			kill(g_tmp, SIGUSR1);
		shifter = 0;
		printed = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.__sigaction_u.__sa_sigaction = sighandle;
	sa.sa_flags = SA_SIGINFO;
	ft_putnbr (getpid());
	write (1, "\n", 1);
	sigaction (SIGUSR1, &sa, NULL);
	sigaction (SIGUSR2, &sa, NULL);
	while (1)
		pause ();
}
