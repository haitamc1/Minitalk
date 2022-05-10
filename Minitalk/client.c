/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 01:51:56 by hchahid           #+#    #+#             */
/*   Updated: 2022/05/10 18:34:38 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, char c)
{
	int	count;

	count = 7;
	while (count >= 0)
	{
		if ((c >> count) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(800);
		count--;
	}
}

void	s_msg(int sig)
{
	if (sig == SIGUSR1)
		write(1, "MESSAGE SENT SUCCESSFULLY\n", 27);
}

int	main(int ac, char **av)
{
	int	pid;
	int	len;
	int	i;	

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			return (write(1, "INVALID PID\n", 12));
		len = ft_strlen(av[2]);
		i = 0;
		signal(SIGUSR1, s_msg);
		while (i <= len)
			send(pid, av[2][i++]);
	}
	else
		write (1, "INVALID NUMBER ARGUMENTS\n", 25);
}
