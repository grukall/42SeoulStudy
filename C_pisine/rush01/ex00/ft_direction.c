/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:29:15 by seungule          #+#    #+#             */
/*   Updated: 2023/01/22 17:36:02 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>
int	ft_direction_up(int **base, int **map, int col)
{
	int	row_i;
	int	nope;
	int	check;

	row_i = 0;
	nope = 0;
	check = 0;
	while (row_i <= 3)
	{
	printf("3");
		if (row_i == 0 && map[row_i][col] != 0)
			check++;
		else
			nope = ft_up(map, row_i, col, nope);
		if (nope == 0 && row_i != 0)
			check++;
		nope = 0;
		row_i++;
	}
	if (check > base[0][col])
		return (0);
	return (1);
}

int	ft_up(int **map, int row_i, int col, int nope)
{
	int	temp;

	temp = row_i - 1;
	while (temp >= 0)
	{
		if (map[temp][col] >= map[row_i][col])
		{	
			nope = 1;
			break ;
		}
		temp--;
	}
	return (nope);
}

int	ft_direction_down(int **base, int **map, int col)
{
	int	row_i;
	int	nope;
	int	check;

	row_i = 3;
	nope = 0;
	check = 0;
	while (row_i >= 0)
	{
	printf("4");
		if (row_i == 3 && map[row_i][col] != 0)
			check++;
		else
			nope = ft_down(map, row_i, col, nope);
		if (nope == 0 && row_i != 3)
			check++;
		nope = 0;
		row_i--;
	}
	if (check > base[1][col])
		return (0);
	return (1);
}

int	ft_down(int **map, int row_i, int col, int nope)
{
	int	temp;

	temp = row_i + 1;
	while (temp <= 3)
	{
		if (map[temp][col] >= map[row_i][col])
		{
			nope = 1;
			break ;
		}
		temp++;
	}
	return (nope);
}
