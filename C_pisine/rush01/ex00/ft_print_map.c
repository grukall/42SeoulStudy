/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:46:18 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/21 20:08:05 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_print_map(int **map)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			temp = map[i][j] + '0';
			write(1, &temp, 1);
			if (!((j + 1) % 4 == 0))
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
/*
int main(void)
{
	int **map;
	map = (int **)malloc(sizeof(int *) * 4);
	int pt1[4] = {1,2,3,4};
	int pt2[4] = {2,1,3,3};
	int pt3[4] = {3, 4 , 2, 1};
	int pt4[4] = {1, 3 ,2 ,2};
	map[0] = pt1;
	map[1] = pt2;
	map[2] = pt3;
	map[3] = pt4;
	ft_print_map(map);
}
*/
