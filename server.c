/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruano-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:27:25 by mruano-m          #+#    #+#             */
/*   Updated: 2023/09/18 10:28:03 by mruano-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//Die Funktion ft_reciever empfängt Signale und setzt das entsprechende
// Bit in einem Byte,
//wobei jedes empfangene Byte Bit für Bit wiederhergestellt wird und am
// Ende als ASCII-Zeichen ausgegeben wird

void	ft_reciever(int signal)
{
	static int	bit;
	static int	c;

	if (signal == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("Server PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, ft_reciever);
	signal(SIGUSR2, ft_reciever);
	while (1)
		pause();
}
