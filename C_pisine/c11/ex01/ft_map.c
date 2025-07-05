/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:33:04 by seungule          #+#    #+#             */
/*   Updated: 2023/02/02 18:57:20 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*result;

	i = 0;
	result = (int *)malloc(sizeof(int) * length);
	while (i < length)
	{
		result[i] = f(tab[i]);
		i++;
	}
	return (result);
}
