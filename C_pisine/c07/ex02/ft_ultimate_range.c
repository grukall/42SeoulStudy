/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:10:34 by seungule          #+#    #+#             */
/*   Updated: 2023/01/28 21:45:04 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (range == 0)
		return (-1);
	while (i < max - min)
	{
		**range = min + i;
		(*range)++;
		i++;
	}
	*range -= i;
	return (max - min);
}
