/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:39:38 by seungule          #+#    #+#             */
/*   Updated: 2023/02/02 06:03:03 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "info.h"

int	check1(char *buf, int check)
{
	int	i;

	i = 0;
	if (check == 0)
		return (0);
	while (buf[i])
	{
		if ((buf[i] < 32 || buf[i] > 126) && buf[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check2(char *buf, int check, t_map_info *map_inf)
{
	int	i;

	i = 0;
	if (check == 0)
		return (0);
	while (buf[i])
	{
		if ((buf[i] < 32 || buf[i] > 126) && buf[i] != '\n')
			return (0);
		if (buf[i] != map_inf->dot
			&& buf[i] != map_inf->block
			&& buf[i] != map_inf->answer
			&& buf[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	check3(char *buf, int check, t_map_info *map_inf)
{
	int	i;

	i = 0;
	if (check == 0)
		return (0);
	if ((*buf < 32 || *buf > 126) && *buf != '\n')
		return (0);
	if (*buf != map_inf->dot
		&& *buf != map_inf->block
		&& *buf != map_inf->answer
		&& *buf != '\n')
		return (0);
	return (1);
}

void	print_error(void)
{
	write(1, "Map Error", 9);
	exit(1);
}
