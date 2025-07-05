/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by seunlee2          #+#    #+#             */
/*   Updated: 2023/02/01 17:56:36 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "info.h"

void	ft_init_chk(int	**chk, t_map_info map_inf);
void	ft_make_chk(int **chk, t_map_info map_inf);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	ft_print_result(char **map, t_map_info map_inf);

void	ft_print_map(char **map);
void	ft_print_chk(int **chk);

#include <stdio.h> // After Done Tasks, Please Delete This.

void	ft_bsq(char **map, t_map_info map_inf)
{
	int	**chk;
	int	i;
	int	j;

	chk = (int **)malloc(sizeof(int *) * map_inf.y);
	ft_make_chk(chk, map_inf);
	ft_init_chk(chk, map_inf);
	int idx;
	idx = 0;
	while (idx < map_inf.x)
	{
		if (map[0][idx] == map_inf.dot)
			chk[0][idx] = 1;
		idx++;
	}
	idx = 0;
	while (idx < map_inf.y)
	{
		if (map[idx][0] == map_inf.dot)
			chk[idx][0] = 1;
		idx++;
	}
	map_inf.res_size = 0;
	i = 1;
	while (i < map_inf.y)
	{
		j = 1;
		while (j < map_inf.x)
		{
			if (map[i][j] != map_inf.block)
			{
				chk[i][j] = ft_min(chk[i - 1][j - 1], chk[i - 1][j]);
				chk[i][j] = 1 + ft_min(chk[i][j], chk[i][j - 1]);
				if (map_inf.res_size != ft_max(map_inf.res_size, chk[i][j]))
				{
					map_inf.res_x = j;
					map_inf.res_y = i;
					map_inf.res_size = ft_max(map_inf.res_size, chk[i][j]);
				}
			}
			j++;
		}
		i++;
	}
	// ft_print_map(map);
	// ft_print_chk(chk);
	printf("( col => %d, row => %d, size => %d )\n", map_inf.res_y, map_inf.res_x, map_inf.res_size);
	ft_print_result(map, map_inf);
}
