/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:05:54 by rosta-c           #+#    #+#             */
/*   Updated: 2024/09/30 11:14:19 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_numbers(char **av);
static bool	check_limits(t_vars *philo);
static void	init_vars(t_vars *philo);
static void	philos_start(t_vars *philo);

bool	init_philo(t_vars *philo, int ac, char **av)
{
	memset (philo, 0, sizeof(t_vars));
	if (ac != 5 && ac != 6)
	{
		printf("Error.\nWrong number of args.\n");
		return (EXIT_FAILURE);
	}
	if (check_numbers(av) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	init_vars(philo);
	philo->n_philos = ft_atoi(av[1]);
	philo->t_2eat = ft_atoi(av[3]);
	philo->t_2sleep = ft_atoi(av[4]);
	philo->t_2die = ft_atoi(av[2]);
	if (ac == 6)
		philo->max_rounds = ft_atoi(av[5]);
	else
		philo->max_rounds = -1;
	if (check_limits(philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	philos_start(philo);
	return (EXIT_SUCCESS);
}

static void	init_vars(t_vars *philo)
{
	philo->start_time = ft_time_ms();
	philo->how_many_r_full = 0;
	philo->philo_dead = false;
	philo->philos_full = false;
	philo->philosophers->last_meal = 0;
	philo->philosophers->meal_nbr = 0;
}

static bool	check_numbers(char **av)
{
	int	x;
	int	z;

	x = 1;
	while (av[x])
	{
		z = 0;
		while (av[x][z] != '\0')
		{
			if (av[x][z] >= 48 && av[x][z] <= 57)
				z++;
			else
			{
				printf("Error.\nargs must be only positive numbers.\n");
				return (EXIT_FAILURE);
			}
		}
		x++;
	}
	return (EXIT_SUCCESS);
}

static bool	check_limits(t_vars *philo)
{
	if (philo->n_philos < 1 || philo->n_philos > 200)
	{
		printf("Error.\nNbr philos must be between 1 and 200\n");
		return (EXIT_FAILURE);
	}
	if (philo->t_2die < 60 || philo->t_2die > INT_MAX)
	{
		printf("Error.\nTime2die is wrong.\n");
		return (EXIT_FAILURE);
	}
	if (philo->t_2eat < 60 || philo->t_2eat > INT_MAX \
		|| philo->t_2sleep < 60 || philo->t_2sleep > INT_MAX)
	{
		printf ("Error.\nTime2eat or Time2sleep is wrong.\n");
		return (EXIT_FAILURE);
	}
	if (philo->max_rounds < -1 || philo->max_rounds > INT_MAX)
	{
		printf("Error.\nAmout of rounds is wrong.\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	philos_start(t_vars *philo)
{
	int	x;

	x = 0;
	while (x < philo->n_philos)
	{
		philo->philosophers[x].philo_nbr = x + 1;
		philo->philosophers[x].last_meal = philo->start_time;
		philo->philosophers[x].vars = philo;
		pthread_mutex_init(&philo->philosophers[x].l_fork, NULL);
		if (x + 1 == philo->n_philos)
		{
			philo->philosophers[x].r_fork = &philo->philosophers[0].l_fork;
		}
		else
			philo->philosophers[x].r_fork = &philo->philosophers[x + 1].l_fork;
		x++;
	}
}
