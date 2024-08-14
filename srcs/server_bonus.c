/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:35 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/14 14:01:15 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *setn)
{
	static unsigned char	c;
	static int				i;

	(void)setn;
	c |= (signum == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			kill(info->si_pid, SIGUSR1);
			ft_printf("\n");
		}
		else
			ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

void	siginit(int signum, void (*h)(int, siginfo_t *, void *))
{
	struct sigaction	s;

	s.sa_sigaction = h;
	sigemptyset(&s.sa_mask);
	s.sa_flags = SA_SIGINFO;
	if (signum == SIGUSR1)
		sigaction(SIGUSR1, &s, NULL);
	else if (signum == SIGUSR2)
		sigaction(SIGUSR2, &s, NULL);
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	siginit(SIGUSR1, signal_handler);
	siginit(SIGUSR2, signal_handler);
	while (1)
		sleep(1);
}
