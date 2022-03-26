/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:07:03 by faventur          #+#    #+#             */
/*   Updated: 2022/03/26 18:45:36 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

#include <stdio.h>

void	my_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		printf("Received SIGUSR1!\n");
	}
}

int	main(int argc, char *argv[])
{
	signal(SIGUSR1, my_handler);
	if (argc == 3)
	{
		printf("%s\n", argv[2]);
		return (0);
	}
	return (1);
}
