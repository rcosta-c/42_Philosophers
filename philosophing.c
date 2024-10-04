/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:15:33 by rosta-c           #+#    #+#             */
/*   Updated: 2024/10/04 22:16:39 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	ft_philo_eat(t_data *philo_x);
static bool	ft_philo_sleep_think(t_data *philo_x);
static bool	ft_check_fork_even(t_data *philo_x);
static bool	ft_check_fork_odd(t_data *philo_x);

void	*philosophing(void *philo)
{
	t_data	*philo_x;

	philo_x = (t_data *)philo;
	ft_waitphilo(philo_x);
	while (1)
	{
		if (philo_x->vars->n_philos == 1)
		{
			ft_one_philo(philo_x);
			break ;
		}
		if (philo_x->philo_nbr % 2 == 0)
		{
			if (!ft_check_fork_even(philo_x))
				break ;
		}
		else
			if (!ft_check_fork_odd(philo_x))
				break ;
		ft_philo_eat(philo_x);
		if (!ft_philo_sleep_think(philo_x))
			break ;
	}
	return (NULL);
}

static bool	ft_check_fork_even(t_data *philo_x)
{
	if (!ft_checker_full_death(philo_x))
		return (false);
	pthread_mutex_lock(philo_x->r_fork);
	if (!ft_checker_message(philo_x, "has taken a fork"))
	{
		pthread_mutex_unlock(philo_x->r_fork);
		return (false);
	}
	if (!ft_checker_full_death(philo_x))
		return (false);
	pthread_mutex_lock(&philo_x->l_fork);
	if (!ft_checker_message(philo_x, "has taken a fork"))
	{
		pthread_mutex_unlock(philo_x->r_fork);
		pthread_mutex_unlock(&philo_x->l_fork);
		return (false);
	}
	return (true);
}

static bool	ft_check_fork_odd(t_data *philo_x)
{
	if (!ft_checker_full_death(philo_x))
		return (false);
	pthread_mutex_lock(&philo_x->l_fork);
	if (!ft_checker_message(philo_x, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo_x->l_fork);
		return (false);
	}
	if (!ft_checker_full_death(philo_x))
		return (false);
	pthread_mutex_lock(philo_x->r_fork);
	if (!ft_checker_message(philo_x, "has taken a fork"))
	{
		pthread_mutex_unlock(&philo_x->l_fork);
		pthread_mutex_unlock(philo_x->r_fork);
		return (false);
	}
	return (true);
}

static bool	ft_philo_eat(t_data *philo_x)
{
	if (!ft_checker_full_death(philo_x))
		return (false);
	pthread_mutex_lock(&philo_x->vars->sync);
	philo_x->meal_nbr ++;
	philo_x->last_meal = ft_time_ms();
	pthread_mutex_unlock(&philo_x->vars->sync);
	if (!ft_checker_message(philo_x, "is eating"))
		return (false);
	ft_usleep(philo_x->vars->t_2eat, philo_x);
	pthread_mutex_lock(&philo_x->vars->sync);
	if (philo_x->vars->max_rounds == philo_x->meal_nbr)
	{
		philo_x->vars->how_many_r_full += 1;
	}
	pthread_mutex_unlock(&philo_x->vars->sync);
	pthread_mutex_unlock(&philo_x->l_fork);
	pthread_mutex_unlock(philo_x->r_fork);
	return (true);
}

static bool	ft_philo_sleep_think(t_data *philo_x)
{
	if (!ft_checker_message(philo_x, "is sleeping"))
		return (false);
	ft_usleep(philo_x->vars->t_2sleep, philo_x);
	if (!ft_checker_message(philo_x, "is thinking"))
		return (false);
	return (true);
}
