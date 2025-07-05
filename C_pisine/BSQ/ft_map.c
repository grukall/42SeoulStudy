/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:49:29 by seunlee2          #+#    #+#             */
/*   Updated: 2023/02/01 04:26:49 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_print_map(char **map)
{
	int	idx;
	int	width;

	idx = 0;
	while (idx < 10)
	{
		width = 0;
		while (width < 10)
		{
			printf("%c", map[idx][width]);
			width++;
		}
		printf("\n");
		idx++;
	}
}
