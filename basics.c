/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosta-c <rcosta-c@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:06:14 by rosta-c           #+#    #+#             */
/*   Updated: 2024/09/19 08:06:15 by rosta-c          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	x;
	int	reslt;
	int	signal;

	x = 0;
	signal = 1;
	reslt = 0;
	while ((nptr[x] >= 9 && nptr[x] <= 13) || nptr[x] == 32)
		x++;
	if (nptr[x] == '-' || nptr[x] == '+')
	{
		if (nptr[x] == '-')
			signal = -1;
		x++;
	}
	while (nptr[x] >= 48 && nptr[x] <= 57)
	{
		reslt *= 10;
		reslt += nptr[x] - 48;
		x++;
	}
	return (reslt * signal);
}