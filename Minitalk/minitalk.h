/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 03:52:25 by hchahid           #+#    #+#             */
/*   Updated: 2022/05/10 18:34:55 by hchahid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putnbr(long long n);
void	ft_putchar(char c);
void	s_msg(int sig);
void	sighandle(int sig, siginfo_t *siginfo, void *old_action);
void	reset(char *printed, int *shifter, int tmp);
void	send(int pid, char c);
int		ft_atoi(const char *str);
int		ft_strlen(char *s);

#endif
