/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosta-c <rcosta-c@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:06:07 by rosta-c           #+#    #+#             */
/*   Updated: 2024/09/19 09:44:24 by rosta-c          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//void	create_check_join(t_vars philo);
//void	detach_destroy(t_vars philo);

int	main(int ac, char **av)
{
	t_vars	philo;
	int		i;
	int		nbr;

	init_philo(&philo, ac, av);
	i = 0;
	nbr = philo.n_philos;
	while (i < nbr)
	{
		pthread_create(&philo.philosophers[i].thread, NULL, philosophing, \
			&philo.philosophers[i]);
		i++;
	}
	i = 0;
	while (i++ < nbr && ft_checker_philos(&philo, &i) == false)
		i = i + 0;
	i = 0;
	while (i < nbr)
	{
		pthread_join(philo.philosophers[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < nbr)
	{
		pthread_mutex_destroy(&philo.philosophers[i].l_fork);
		i++;
	}
	exit(EXIT_SUCCESS);
}
/*
void	create_check_join(t_vars philo)
{
	int	x;

	x = 0;
		printf("\n\nAAAAAAAAAAAAAAAAAAAA-estouaqui\n\n");

	while (x < philo.n_philos)
	{
		pthread_create(&philo.philosophers[x].thread, NULL, philosophing, \
			&philo.philosophers[x]);
		x++;
	}
	x = 0;
			printf("\n\nVVVVVVVVVV-estouaqui\n\n");

	while (x++ < philo.n_philos && ft_checker_philos(&philo, &x) == true)
	{
		x = x + 0;
	}
	//while (x < philo.n_philos)
	//{
	//	if (ft_checker_philos(&philo, &x) == true)
	//		break ;
	//	x++;
	//}
	x = 0;		
	printf("\n\nZZZZZZZZZZZZ-estouaqui\n\n");

	while (x < philo.n_philos)
	{
		printf("\n\nZZZZ312832138172831783178371ZZZZZZZZ-estouaqui\n\n");
		pthread_join(philo.philosophers[x].thread, NULL);
		x++;
	}
	printf("\n\nDEEESSSSTROOYYYYYYY-estouaqui\n\n");
	detach_destroy(philo);
	printf("\n\nDEEESSSSTROOYYnDEEESSSSTROOYYYYYYYYYYYY-estouaqui\n\n");
}

void	detach_destroy(t_vars philo)
{
	int	x;

	x = 0;
	while (x < philo.n_philos)
	{
		pthread_detach(philo.philosophers[x].thread);
		x++;
	}
	x = 0;
	while (x < philo.n_philos)
	{
		pthread_mutex_destroy(&philo.philosophers[x].l_fork);
	}
}*/
