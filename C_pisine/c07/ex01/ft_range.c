/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:29:32 by seungule          #+#    #+#             */
/*   Updated: 2023/01/25 12:12:03 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	result = (int *)malloc(sizeof(int) * (max - min));
	while (max - min)
	{
		result[i] = min;
		min++;
		i++;
	}
	return (result);
}
