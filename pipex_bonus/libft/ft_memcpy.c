/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:16:51 by seungule          #+#    #+#             */
/*   Updated: 2023/07/25 14:23:48 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	const char	*tempsrc;
	char		*tempdest;

	tempsrc = source;
	tempdest = dest;
	if (!source && !dest)
		return (dest);
	if (num)
	{
		while (num--)
		*(tempdest++) = *(tempsrc++);
	}
	return (dest);
}
