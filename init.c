/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosta-c <rcosta-c@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:05:54 by rosta-c           #+#    #+#             */
/*   Updated: 2024/09/19 09:56:28 by rosta-c          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_numbers(char **av);
static void	check_limits(t_vars *philo);
static  void    philos_start(t_vars *philo);

void	init_philo(t_vars *philo, int ac, char **av)
{
    memset(&philo, 0, sizeof(t_vars));
//  bzero(&philo, sizeof(t_vars));
    if(ac != 5 && ac != 6)
	{
		printf("Error\n\nwrong number of args.\n");
		exit(EXIT_FAILURE);
	}
	check_numbers(av);
	philo->n_philos = ft_atoi(av[1]);
	philo->t_2eat = ft_atoi(av[3]);
	philo->t_2sleep = ft_atoi(av[4]);
	philo->t_2die = ft_atoi(av[2]);
	if (av[5])
		philo->max_rounds = ft_atoi(av[5]);
	else
		philo->max_rounds = -1;
	check_limits(philo);
    philo->start_time = ft_time_ms;
    philos_start(philo);
}

static void	check_numbers(char **av)
{
	int	x;
	int	z;
	
	x = 1;
	while(av[x])
	{
		z = 0;
		while(av[x][z] != '\0')
		{
			if (av[x][z] >= 48 && av[x][z] <= 57)
				z++;
			else
			{
				printf("Error.\nargs must be only numbers.\n");
				exit(EXIT_FAILURE);
			}
		}
		x++;
	}
}

static void	check_limits(t_vars *philo)
{
	if (philo->n_philos < 1 || philo->n_philos > 200)
	{
		printf("Error\n. Number of philosophers has to be between 1 and 200.\n");
		exit(EXIT_FAILURE);
	}
	if (philo->t_2die < 0 || philo->t_2die > INT_MAX)
	{
		printf("Error.\n Amout of time to a philo will die if he doesn’t eat, is wrong.\n");
		exit (EXIT_FAILURE);
	}
	if (philo->t_2eat < 0 || philo->t_2eat > INT_MAX || philo->t_2sleep < 0 || philo->t_2sleep > INT_MAX)
	{
		printf("Error.\n Amout of time a philo takes to eat or sleep, is wrong.\n");
		exit (EXIT_FAILURE);
	}
	if (philo->max_rounds)
	{
		if (philo->max_rounds < 0 || philo->max_rounds > INT_MAX)
		{
			printf("Error.\n Amout of time philosophers must eat, is wrong.\n");
			exit (EXIT_FAILURE);
		}
	}
}

static  void    philos_start(t_vars *philo)
{
    int x;

    x = 0;
    while (x < philo->n_philos)
    {
        philo->philosophers[x]->philo_nbr = x + 1;
        philo->philosophers[x]->last_meal = ft_time_ms;
        pthread_mutex_init(&philo->philosophers[x].l_fork, NULL);
        if(x + 1 == philo->n_philos)
        {
            philo->philosophers[x].r_fork = philo->philosophers[0].l_fork;
        }
        else
            philo->philosophers[x].r_fork = philo->philosophers[x + 1].l_fork;
        x++;
    }
    
}