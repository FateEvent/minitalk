/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:19:24 by faventur          #+#    #+#             */
/*   Updated: 2022/04/05 20:35:41 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"

static int	ft_power(int n, int power)
{
	int	result;

	if (power < 0 || !n)
		return (0);
	result = 1;
	while (power--)
		result *= n;
	return (result);
}

static char	mt_binary2char(char *binary)
{
	char	c;
	int		i;
	int		y;

	if (!binary)
		return (0);
	i = 7;
	y = 0;
	c = 0;
	while (i >= 0)
	{
		if (binary[i] == '1')
			c += ft_power(2, y);
		i--;
		y++;
	}
	return (c);
}

static void	receive_message(int signum)
{
	static char	buffer[9];
	static int	i;
	char		c;

	if (signum == SIGUSR1)
		buffer[i++] = '1';
	else
		buffer[i++] = '0';
	if (i >= 8)
	{
		buffer[i] = '\0';
		c = mt_binary2char(buffer);
		if (!c)
			ft_putchar('\n');
		else
			ft_putchar(c);
		ft_bzero(buffer, 9);
		i = 0;
	}
}

void	my_handler(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Received SIGUSR1!\n");
	else
		ft_printf("Eh, ben non\n");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, receive_message);
	signal(SIGUSR2, receive_message);
	while (1)
		pause();
}
