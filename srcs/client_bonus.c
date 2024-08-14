/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:43:58 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/14 14:02:05 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	sendchar(int pid, unsigned char c)
{
	int				i;
	unsigned char	tmp;

	i = 8;
	tmp = c;
	while (i-- > 0)
	{
		tmp = c >> i;
		if (tmp % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	msg_recieved(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Message recieved!\n");
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;
	char	*msg;

	if (argc == 3)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		msg = argv[2];
		signal(SIGUSR1, msg_recieved);
		while (msg[i])
			sendchar(pid, msg[i++]);
		sendchar(pid, '\0');
	}
	else
		ft_printf("Invalid arguments!");
}
