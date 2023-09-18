/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruano-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:35:26 by mruano-m          #+#    #+#             */
/*   Updated: 2023/09/18 10:35:56 by mruano-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str)
	{
		while (str[i] == ' ' || str[i] == '\f' || str[i] == '\t' \
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
			i++;
		if (str[i] == '-')
			sign = -1;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i++] - '0';
	}
	return (sign * nb);
}
