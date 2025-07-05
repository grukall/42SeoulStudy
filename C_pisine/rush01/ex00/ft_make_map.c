/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 14:26:38 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/22 17:25:07 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**ft_map_init(int **map)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		while (k < 4)
		{
			map[i][k] = 0;
			k++;
		}
		k = 0;
		i++;
	}
	return (map);
}

int	ft_base_len(int *base)
{
	int	i;

	i = 0;
	while (base[i] > 0)
		i++;
	return (i);
}

int	**ft_make_map(int N)
{
	int	**map;
	int	i;

	i = 0;
	map = (int **)malloc(sizeof(int *) * N);
	if (!map)
		return (0);
	while (i < N)
	{
		map[i] = (int *)malloc(sizeof(int) * N);
		if (!map[i])
			return (0);
		i++;
	}
	return (ft_map_init(map));
}
int	ft_skyscraper(int *base)
{
	int	n;
	int	i;
	int	**map;
	int	**base_copy;

	n = 4;
	i = 0;
	base_copy = ft_make_base(base);
	map = ft_make_map(n);
	ft_check(base_copy, map, 0, -1);
	return (0);
}
