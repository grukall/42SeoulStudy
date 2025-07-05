/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:05:38 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/22 17:19:40 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"
int **ft_input(int *str, int **base);
int	**ft_make_base(int *str)
{
	int	i;
	int	**base;

	base = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	if (!base)
		return (0);
	while (i < 4)
	{
		base[i++] = (int *)malloc(sizeof(int) * 4);
		if (!base)
			return (0);
	}
	return (ft_input(str, base));
}

int	**ft_input(int *str, int **base)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			base[i][k] = str[j++];
			k++;
		}
		i++;
	}
	return (base);
}
