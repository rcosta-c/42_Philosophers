/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosta-c <rcosta-c@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:15:43 by rosta-c           #+#    #+#             */
/*   Updated: 2024/09/19 08:15:48 by rosta-c          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	checker_death(t_vars *philo, int *x);
static bool	checker_full(t_vars *philo, int *x);

bool	ft_checker_philos(t_vars *philo, int *x)
{
	pthread_mutex_lock(&philo->sync);
	if (checker_death(philo, x))
	{
		pthread_mutex_unlock(&philo->sync);
		return (true);
	}
	if (checker_full(philo, x))
	{
		pthread_mutex_unlock(&philo->sync);
		return (true);
	}
	if (philo->n_philos == *x + 1)
		*x = 0;
	pthread_mutex_unlock(&philo->sync);
	return (false);
}

static bool	checker_death(t_vars *philo, int *x)
{
	if (ft_time_ms() - philo->philosophers[*x].last_meal \
	>= (unsigned long long)philo->t_2die)
	{
		philo->philo_dead = true;
		pthread_mutex_unlock(&philo->philosophers[*x].l_fork);
		printf ("%lu %d died\n", ft_time_ms() - philo->start_time, \
			philo->philosophers[*x].philo_nbr);
		return (true);
	}
	return (false);
}

static bool	checker_full(t_vars *philo, int *x)
{
	if (philo->how_many_r_full == philo->n_philos && philo->max_rounds != -1)
	{
		philo->philos_full = true;
		pthread_mutex_unlock(&philo->philosophers[*x].l_fork);
		printf ("Every philosopher has eaten %d times\n", philo->max_rounds);
		return (true);
	}
	return (false);
}
