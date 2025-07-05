/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:43:04 by seungule          #+#    #+#             */
/*   Updated: 2023/11/12 21:42:02 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_arg
{
	pthread_mutex_t *mutex_fork;
	pthread_mutex_t mutex_print;
	pthread_mutex_t mutex_full;
	pthread_mutex_t mutex_life;
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				life;
	char			*fork;
	char			*full;
}t_arg;

typedef struct s_philo
{
	int		id;
	int		left;
	int		right;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		start_time;
	t_arg	*arg;
}t_philo;

int		ft_atoi(const char *str);
void	print_philo_info(t_arg *philo_info);
int		put_info_philo(t_arg *philo_info, int argc, char **argv);
int		make_philo(t_philo **philo, t_arg *philo_info);
int		init_mutex_and_value(t_arg *philo_info);
int		mutex_init(t_arg *philo_info);

int		start_experiment(t_philo *philo, t_arg *philo_info);
void	*thread(void *ph);
int		eat_start(t_philo *philo);
int		sleep_start(t_philo *philo);

int		print_philo_state(t_philo *philo, char *state);

#endif