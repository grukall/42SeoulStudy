/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:35:29 by seunlee2          #+#    #+#             */
/*   Updated: 2023/02/01 17:50:52 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include <unistd.h>

void	ft_print_result(char **map, t_map_info map_inf)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_inf.y)
	{
		j = 0;
		while (j < map_inf.x)
		{
			if ((map_inf.res_x + 1 - map_inf.res_size <= j
					&& j <= map_inf.res_x)
				&& (map_inf.res_y + 1 - map_inf.res_size <= i
					&& i <= map_inf.res_y))
				write(1, &map_inf.answer, 1);
			else
				write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
