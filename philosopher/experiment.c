/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   experiment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:37:09 by seungule          #+#    #+#             */
/*   Updated: 2023/11/12 21:50:10 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *philo);

int	start_experiment(t_philo *philo, t_arg *philo_info)
{
	pthread_t		*threads_id;
	struct timeval	time;
	int				i;

	i = 0;
	threads_id = (pthread_t *)malloc(sizeof(pthread_t) * philo_info->number_of_philosophers);
	if (!threads_id || gettimeofday(&time, NULL) == -1)
		return (0);
	while (i < philo_info->number_of_philosophers)
	{
		philo[i].start_time = time.tv_usec;
		if(pthread_create(&threads_id[i], NULL, thread, &philo[i]))
			return (0);
		i++;
	}
	while (1)
	{
		if (philo_info->life == 0)
		{
			printf("philo is die\n");
			break ;
		}
	}
	i = 0;
	while (i < philo_info->number_of_philosophers)
		pthread_join(threads_id[i++], NULL);
	return (1);
}

void	*thread(void *ph)
{
	t_philo *philo = (t_philo *)ph;
	if ((philo->id + 1) % 2 == 0)
		usleep(1000);
	while (philo->arg->life)
	{
		if(!eat_start(philo))
		{
			pthread_mutex_lock(&philo->arg->mutex_life);
			philo->arg->life = 0;
			pthread_mutex_unlock(&philo->arg->mutex_life);
			pthread_exit(NULL);
		}
		sleep_start(philo);
	}
	pthread_exit(&philo->id);
}

int	eat_start(t_philo *philo)
{
	print_philo_state(philo, "is eating");
	if (philo->id == 2)
		return (0);
	usleep(100);
	return (1);
}

int	sleep_start(t_philo *philo)
{
	print_philo_state(philo, "is sleeping");
	usleep(100);
	return (1);
}