/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:46:12 by seungule          #+#    #+#             */
/*   Updated: 2023/11/12 21:30:50 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_info(t_arg *philo_info)
{
	printf("number_of_philosophers : %d\n", philo_info->number_of_philosophers);
	printf("time_to_die : %d\n", philo_info->time_to_die);
	printf("time_to_eat : %d\n", philo_info->time_to_eat);
	printf("time_to_sleep : %d\n", philo_info->time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat : %d\n", philo_info->number_of_times_each_philosopher_must_eat);
}

int	put_info_philo(t_arg *philo_info, int argc, char **argv)
{
	if (argc >= 5 && argc <= 6)
	{
		philo_info->number_of_philosophers = ft_atoi(argv[1]);
		if (philo_info->number_of_philosophers < 1)
			return (0);
		philo_info->time_to_die = ft_atoi(argv[2]);
		if (philo_info->time_to_die < 0)
			return (0);
		philo_info->time_to_eat = ft_atoi(argv[3]);
		if (philo_info->time_to_eat < 0)
			return (0);
		philo_info->time_to_sleep = ft_atoi(argv[4]);
		if (philo_info->time_to_sleep < 0)
			return (0);
		if (argc == 6)
			philo_info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		else
			philo_info->number_of_times_each_philosopher_must_eat = 0;
		if (philo_info->number_of_times_each_philosopher_must_eat < 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	make_philo(t_philo **philo, t_arg *philo_info)
{
	int	i;
	int	philo_num;

	i = 0;
	philo_num = philo_info->number_of_philosophers;
	*philo = (t_philo *)malloc(sizeof(t_philo) * philo_num);
	if (!*philo)
		return (0);
	while (i < philo_info->number_of_philosophers)
	{
		(*philo)[i].id = i;
		if (i == 0)
			(*philo)[i].left = philo_num - 1;
		else
			(*philo)[i].left = i - 1;
		(*philo)[i].right = i;
		(*philo)[i].arg = philo_info;
		(*philo)[i].time_to_die = philo_info->time_to_die;
		(*philo)[i].time_to_eat = philo_info->time_to_eat;
		(*philo)[i].time_to_sleep = philo_info -> time_to_sleep;
		i++;
	}
	return (1);
}

int	init_mutex_and_value(t_arg *philo_info)
{
	int	philo_num;

	philo_num = philo_info->number_of_philosophers;
	if (!mutex_init(philo_info))
		return (0);
	philo_info->fork = (char *)malloc(sizeof(char) * (philo_num - 1));
	if (!philo_info->fork)
		return (0);
	philo_info->full = (char *)malloc(sizeof(char) * (philo_num));
	if (!philo_info->full)
		return (0);
	memset(philo_info->fork, '1', philo_num - 1);
	memset(philo_info->full, '0', philo_num);
	philo_info->life = 1;
	return (1);
}

int	mutex_init(t_arg *philo_info)
{
	int	i;

	i = 0;
	philo_info->mutex_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) *
		(philo_info->number_of_philosophers - 1));
	while (i < philo_info->number_of_philosophers - 1)
	{
		if(pthread_mutex_init(&philo_info->mutex_fork[i++], NULL))
			return (0);
	}
	if(pthread_mutex_init(&philo_info->mutex_print, NULL))
		return (0);
	if(pthread_mutex_init(&philo_info->mutex_full, NULL))
		return (0);
	if(pthread_mutex_init(&philo_info->mutex_life, NULL))
		return (0);
	return (1);
}
