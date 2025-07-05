/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:04:08 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/22 18:16:21 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>
int	ft_promising(int**base, int **map, int row, int col)
{
	if (ft_duplicate(base, map, row, col) == 0)
		return (0);
	if (ft_direction_up(base, map, col) == 0)
		return (0);
	if (ft_direction_down(base, map, col) == 0)
		return (0);
	if (ft_direction_left(base, map, row) == 0)
		return (0);
	if (ft_direction_right(base, map, row) == 0)
		return (0);
//	printf("7");
	return (1);
}

void	ft_check(int **base, int **map, int row, int col)
{
	int	i;

	i = 1;
//	printf("\nthis is input : %d\n",map[row][col]);
	if (ft_promising(base, map, row, col))
	{
		if (row == 3 && col == 3)
		{
			ft_print_map(map);
			return ;
		}
		if (col == 3)
		{
			row++;
			col = -1;
		}
		while (i <= 4)
		{
			map[row][col + 1] = i;
			ft_check(base, map, row, col + 1);
			i++;
		}
	}
}
