/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:19:24 by faventur          #+#    #+#             */
/*   Updated: 2022/04/05 16:59:34 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

/*
static void	receive_message(char *msg, int pid_server)
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
			if (c << j & 1)
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
*/
void	my_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Received SIGUSR1!\n");
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d", pid);
	signal(SIGUSR1, my_handler);
	return (0);
}

