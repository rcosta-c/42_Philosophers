/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcosta-c <rcosta-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 08:06:12 by rosta-c           #+#    #+#             */
/*   Updated: 2024/09/30 11:00:36 by rcosta-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <ctype.h>
# include <stdint.h>
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

typedef struct s_data
{
	int				philo_nbr;
	int				meal_nbr;
	uint64_t		last_meal;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	struct s_vars	*vars;
}	t_data;

typedef struct s_vars
{
	int					n_philos;
	int					t_2eat;
	int					t_2sleep;
	int					t_2die;
	int					max_rounds;
	int					how_many_r_full;
	bool				philo_dead;
	bool				philos_full;
	bool				args_error;
	struct s_data		philosophers[200];
	uint64_t			start_time;
	pthread_mutex_t		sync;
}	t_vars;

/*basics.c*/
int			ft_atoi(const char *nptr);
uint64_t	ft_time_ms(void);
int			someone_dead(t_data *philo);
void		ft_usleep(uint64_t time, t_data *philo_x);
bool		ft_checker_full_death(t_data *philo_x);
/*init.c*/
bool		init_philo(t_vars *philo, int ac, char **av);
/*checker.c*/
bool		ft_checker_philos(t_vars *philo, int *x);
bool		ft_checker_message(t_data *philo, char *str);
/*philosophing.c*/
void		*philosophing(void *philo);
/*utils_philo.c*/
void		ft_waitphilo(t_data *philo_x);
void		ft_one_philo(t_data *philo_x);
/*extras*/

#endif
