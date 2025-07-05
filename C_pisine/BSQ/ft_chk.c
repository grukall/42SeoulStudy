/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:37:58 by seunlee2          #+#    #+#             */
/*   Updated: 2023/02/01 17:15:53 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "info.h"

void	ft_make_chk(int **chk, t_map_info map_inf)
{
	int	col;
	int	row;

	col = 0;
	while (col < map_inf.y)
	{
		chk[col] = (int *)malloc(sizeof(int) * (map_inf.x));
		row = 0;
		while (row < map_inf.x)
		{
			chk[col][row] = 0;
			row++;
		}
		col++;
	}
}

void	ft_init_chk(int **chk, t_map_info map_inf)
{
	int	col;
	int	row;

	col = 0;
	while (col < map_inf.y)
	{
		row = 0;
		while (row < map_inf.x)
		{
			chk[col][row] = 0;
			row++;
		}
		col++;
	}
}

void	ft_print_chk(int **chk)
{
	int	col;
	int	row;

	col = 0;
	while (col < 10)
	{
		row = 0;
		while (row < 10)
		{
			printf("%d ", chk[col][row]);
			row++;
		}
		printf("\n");
		col++;
	}
}