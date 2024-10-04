/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:06:14 by rosta-c           #+#    #+#             */
/*   Updated: 2024/10/01 12:12:49 by rcosta-c         ###   ########.fr       */
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
	while (nptr[x] >= '0' && nptr[x] <= '9')
	{
		reslt *= 10;
		reslt += nptr[x] - 48;
		x++;
	}
	if (reslt > INT32_MAX)
		return (-99);
	return (reslt * signal);
}

uint64_t	ft_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	someone_dead(t_data *philo)
{
	pthread_mutex_lock(&philo->vars->sync);
	if (philo->vars->philo_dead)
	{
		pthread_mutex_unlock(&philo->vars->sync);
		return (EXIT_FAILURE);
	}
	else
	{
		pthread_mutex_unlock(&philo->vars->sync);
		return (EXIT_SUCCESS);
	}
}

void	ft_usleep(uint64_t time, t_data *philo_x)
{
	uint64_t	now;

	now = ft_time_ms();
	while (ft_time_ms() - now < time && !someone_dead(philo_x))
	{
		usleep(150);
	}
}
