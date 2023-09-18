/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruano-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:25:15 by mruano-m          #+#    #+#             */
/*   Updated: 2023/09/18 10:25:44 by mruano-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <signal.h>

void	ft_sendbts(char Bit, int pid);
void	ft_reciever(int signal);
int		ft_atoi(const char *str);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_putnbr(int nb);

#endif
