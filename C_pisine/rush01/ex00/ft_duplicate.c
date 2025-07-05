/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:34:05 by seungule          #+#    #+#             */
/*   Updated: 2023/01/22 17:33:33 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>

int	ft_duplicate(int**base, int **map, int row, int col)
{
	if (ft_row(map, row, col) == 0)
		return (0);
	if (ft_col(map, row, col) == 0)
		return (0);
	return (1);
}

int	ft_row(int **map, int row, int col)
{
	int	row_i;

	row_i = 0;
	while (row_i <= row)
	{
	printf("1");
		if (row_i == row)
			row_i++;
		if (row_i >= row)
			break ;
		else if (map[row_i][col] == map[row][col])
			return (0);
		row_i++;
	}
	return (1);
}

int	ft_col(int **map, int row, int col)
{
	int	col_i;

	col_i = 0;
	while (col_i <= col)
	{
	printf("2");
		if (col_i == col)
			col_i++;
		if (col_i >= col)
			break ;
		else if (map[row][col_i] == map[row][col])
			return (0);
		col_i++;
	}
	return (1);
}
