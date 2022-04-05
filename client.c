/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:07:03 by faventur          #+#    #+#             */
/*   Updated: 2022/04/05 16:52:57 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

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
			usleep(100);
		}
		i++;
	}
	j = 8;
	while (j--)
	{
		kill(pid_server, SIGUSR2);
		usleep(100);
	}
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
	send_message(pid_server, argv[2]);
	return (0);
}
