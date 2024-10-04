/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:16:12 by rosta-c           #+#    #+#             */
/*   Updated: 2024/10/04 11:24:16 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_waitphilo(t_data *philo_x)
{
	if (!(philo_x->philo_nbr & 1))
		ft_usleep(10, philo_x);
}

void	ft_one_philo(t_data *philo_x)
{
	pthread_mutex_lock(&philo_x->vars->sync);
	printf("0 1 has taken a fork\n");
	pthread_mutex_unlock(&philo_x->vars->sync);
}
