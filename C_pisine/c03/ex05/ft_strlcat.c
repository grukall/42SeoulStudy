/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:22:25 by seungule          #+#    #+#             */
/*   Updated: 2023/01/18 19:09:59 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_size(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	src_size;
	unsigned int	i;

	dest_size = str_size(dest);
	src_size = str_size(src);
	i = 0;
	if (size <= dest_size)
		return (size + src_size);
	else
	{
		while (src[i] && (i < size - dest_size - 1))
		{
			dest[dest_size + i] = src[i];
			i++;
		}
		dest[dest_size + i] = '\0';
		return (dest_size + src_size);
	}
}

unsigned int	str_size(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
