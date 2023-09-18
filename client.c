/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruano-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 09:51:50 by mruano-m          #+#    #+#             */
/*   Updated: 2023/07/27 09:52:34 by mruano-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//Die Funktion "ft_sendbts" übermittelt eine Nachricht an den Server, 
//indem sie jedes einzelne Bit (1 oder 0) der Nachricht umwandelt und 
//entweder das Signal SIGUSR1 oder SIGUSR2 an den Server schickt. 
//Dadurch wird die Nachricht Bit für Bit übermittelt.(SIGUSR2 = 0 ; SIGUSR1 = 1)

void	ft_sendbts(char Bit, int pid)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (Bit & (1 << bits))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bits++;
	}
}

//Dieser Code sendet eine Nachricht an den Server mit einer der PID,
//wobei die PID und die Nachricht als Argumente beim Aufruf des Programms
// übergeben werden.
//argc = <message> **argv = <pid_server>
//ft_atoi wandelt die pid_server in eine Ganzzahl um und gibt die 
//Variable pid
//Achtung Wichtig mehr wie 2 Argumente verwenden, ansonsten kommt
//eine Fehlermeldung 

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_putstr("WRONG YOU NEED MORE THAN 2 ARGUMENT\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		ft_sendbts(argv[2][i], pid);
		i++;
	}
	ft_sendbts('\0', pid);
}
