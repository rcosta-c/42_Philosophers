/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosta-c <rcosta-c@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:15:33 by rosta-c           #+#    #+#             */
/*   Updated: 2024/09/19 09:40:57 by rosta-c          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philosophing(t_vars *philo)
{

	
}

size_t  ft_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return(time.tv_sec * 1000 + time.tv_usec / 1000);		
}

void	ft_usleep(int time)
{
	int	now;

	now = ft_time_ms;
	while(ft_time_ms - now < time)
	{
		usleep(150);
	}
}
