/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosta-c <rcosta-c@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:06:12 by rosta-c           #+#    #+#             */
/*   Updated: 2024/09/19 09:41:34 by rosta-c          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <pthread.h>


typedef struct s_vars
{
	int			n_philos;
	int			t_2eat;
	int			t_2sleep;
	int			t_2die;
	int			max_rounds;
	bool	all_eat;
	t_data			philosophers[200];
	uint64_t		start_time;
//	uint64_t		current_time;
	pthread_mutex_t		sync;
}	t_vars;

typedef struct s_data
{
	int		philo_nbr;
	size_t	last_meal;
	bool	dead;
	bool	l_fork;
	bool	r_fork;
	pthread_mutex_t		thread;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		r_fork;
}	t_data;

int	ft_atoi(const char *nptr);
size_t	ft_time_ms(void);
void	init_philo(t_vars *philo, int ac, char **av);
void	philosophing(t_vars *philo);
void	ft_usleep(int time);
	

#endif
