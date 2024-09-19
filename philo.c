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

int main(int ac, char **av)
{
	t_vars	philo;
	int		x;
	
	init_philo(&philo, ac, av);
//create_check_join()FUNCAO A CONSTRUIR PARA ALBERGAR "pthread_create e pthread_join"
//								albergar tambem o check_philos()
	x = 0;
	while(x < philo.n_philos)
	{
		pthread_create(&philo.philosophers[x].thread, NULL, philosophing, &philo.philosophers[x]);
		x++;
	}
	x = 0;
	while (x < philo.n_philos)
	{
		checker_philos(&philo, &x);		
	}
	x = 0;
	while (x < philo.n_philos)
	{
		pthread_join( , );
		x++;
	}
//				create_check_join()    ATE AQUI!!!
//	detach_destroy()FUNCAO PARA ALBERGAR "pthread_detach e pthread_mutex_destroy"
	x = 0;
	while (x < philo.n_philos)
	{
		pthread_detach(&philo);
		x++;
	}
	x = 0;
	while (x < philo.n_philos)
	{
		pthread_mutex_destroy(&philo);
	}	
//				detach_destroy()    ATE AQUI!!!
	return (0);
}
