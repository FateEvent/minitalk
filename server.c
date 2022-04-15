/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:19:24 by faventur          #+#    #+#             */
/*   Updated: 2022/04/15 16:58:38 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

static char	ft_binary2char(char *binary)
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

static void	receive_message(int signum, siginfo_t *info, void *context)
{
	static char	buffer[8];
	static int	i;
	char		c;

	if (signum == SIGUSR1)
		buffer[i++] = '1';
	else
		buffer[i++] = '0';
	if (i >= 8)
	{
		buffer[i] = '\0';
		c = ft_binary2char(buffer);
		if (!c)
		{
			ft_putchar('\n');
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_putchar(c);
		ft_bzero(buffer, 9);
		i = 0;
	}
	context = 0;
}

int	main(void)
{
	struct sigaction	sa;	

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_message;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
}
