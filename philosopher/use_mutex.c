/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:09:17 by seungule          #+#    #+#             */
/*   Updated: 2023/11/12 21:41:59 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_philo_state(t_philo *philo, char *state)
{
	struct timeval print_time;
	pthread_mutex_lock(&philo->arg->mutex_print);
	if (gettimeofday(&print_time, NULL) == -1)
		return (0);
	printf("%d %d %s\n", print_time.tv_usec - philo->start_time, philo->id + 1, state);
	pthread_mutex_unlock(&philo->arg->mutex_print);
	return (0);
}