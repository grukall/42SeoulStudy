/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:41:00 by seungule          #+#    #+#             */
/*   Updated: 2023/11/12 21:44:13 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_arg 			philo_info;
	t_philo			*philo;
	int				error_num;

	if (!put_info_philo(&philo_info, argc, argv))
		return (printf("invalid argument\n"));
	//print_philo_info(&philo_info);
	if (!make_philo(&philo, &philo_info))
		return (printf("failed make philo\n"));
	if (!init_mutex_and_value(&philo_info))
		return (printf("failed init mutex or value\n"));
	error_num = start_experiment(philo, &philo_info);
	if (error_num == 0)
		return (printf("failed to start experiment"));
	return (0);
}
