/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:07:03 by faventur          #+#    #+#             */
/*   Updated: 2022/04/05 21:58:08 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(int pid_server, char *msg)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	while (msg[i])
	{
		j = 8;
		c = msg[i];
		while (j--)
		{
			if (c >> j & 1)
				kill(pid_server, SIGUSR1);
			else
				kill(pid_server, SIGUSR2);
			usleep(50);
		}
		i++;
	}
	j = 8;
	while (j--)
	{
		kill(pid_server, SIGUSR2);
		usleep(50);
	}
}

void	reception_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Roger!\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
	int	pid_server;

	if (argc != 3)
	{
		ft_printf("Expected arguments: ./client [PID] [MESSAGE]");
		return (1);
	}
	pid_server = ft_atoi(argv[1]);
	signal(SIGUSR1, reception_handler);
	send_message(pid_server, argv[2]);
	sleep(3);
	ft_printf("Houston, we have a problem!\n");
	return (1);
}
