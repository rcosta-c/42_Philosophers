/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:06:07 by rosta-c           #+#    #+#             */
/*   Updated: 2024/09/27 10:53:37 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	create_check_join(t_vars *philo);
static void	destroyer(t_vars *philo);

int	main(int ac, char **av)
{
	t_vars	philo;

	init_philo(&philo, ac, av);
	create_check_join(&philo);
	destroyer(&philo);
	return (EXIT_SUCCESS);
}

static void	create_check_join(t_vars *philo)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = philo->n_philos;
	while (i < nbr)
	{
		pthread_create(&philo->philosophers[i].thread, NULL, philosophing, \
			&philo->philosophers[i]);
		i++;
	}
	i = -1;
	while (++i < nbr && !ft_checker_philos(philo, &i))
		i = i + 0;
	i = 0;
	while (i++ < nbr)
		pthread_join(philo->philosophers[i].thread, NULL);
}

static void	destroyer(t_vars *philo)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = philo->n_philos;
	while (i < nbr)
	{
		pthread_mutex_destroy(&philo->philosophers[i].l_fork);
		pthread_mutex_destroy(philo->philosophers[i].r_fork);
		i++;
	}
	pthread_mutex_destroy(&philo->sync);
}
