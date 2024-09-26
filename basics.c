/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:06:14 by rosta-c           #+#    #+#             */
/*   Updated: 2024/09/24 09:50:42 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int			x;
	long int	reslt;
	int			signal;

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

uint64_t	ft_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(uint64_t time)
{
	uint64_t	now;

	now = ft_time_ms();
	while (ft_time_ms() - now < time)
	{
		usleep(150);
	}
}

bool	ft_checker_full_death(t_data *philo_x)
{
	pthread_mutex_lock(&philo_x->vars->sync);
	if (philo_x->vars->philos_full)
	{
		pthread_mutex_unlock(&philo_x->vars->sync);
		return (false);
	}
	if (philo_x->vars->philo_dead)
	{
		pthread_mutex_unlock(&philo_x->vars->sync);
		return (false);
	}
	pthread_mutex_unlock(&philo_x->vars->sync);
	return (true);
}
