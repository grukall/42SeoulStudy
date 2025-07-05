/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:00:03 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/22 16:53:01 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
#include <stdio.h>
int	ft_direction_left(int **base, int **map, int row)
{
	int check;
	int col_i;
	int nope;

	check = 0;
	col_i = 0;
	nope = 0;
	while(col_i <= 3)
	{
		printf("5");
		if(col_i == 0 && map[row][col_i] != 0)
			check++;
		else
			nope = ft_left(map, col_i, row, nope);
		if (nope == 0 && col_i != 0)
			check++;
		nope = 0;
		col_i++;
	}
	if (check > base[2][row])
		return 0;
	return (1);
}
int	ft_left(int **map, int col_i, int row, int nope)
{
	int temp;

	temp = col_i - 1;
	while (temp >= 0)
	{
		printf("6");
		if(map[row][temp] >= map[row][col_i])
		{
			nope = 1;
			break;
		}
		temp--;
	}
	return (nope);
}
int	ft_direction_right(int **base, int **map, int row)
{
	int check;
	int col_i;
	int nope;

	nope = 0;
	check = 0;
	col_i = 3;
	while(col_i >= 0)
	{
		if(col_i == 3 && map[row][col_i] != 0)
			check++;
		else
			nope = ft_right(map, col_i, row, nope);
		if (nope == 0 && col_i != 3)
			check++;
		nope = 0;
		col_i--;
	}
	if (check > base[3][row])
		return 0;
	return (1);
}

int	ft_right(int **map, int col_i, int row, int nope)
{
	int temp;

	temp = col_i + 1;
	while (temp <= 3)
	{
		if(map[row][temp] >= map[row][col_i])
		{
			nope = 1;
			break;
		}
		temp++;
	}
	return (nope);
}
