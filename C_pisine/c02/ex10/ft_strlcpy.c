/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:23:22 by seungule          #+#    #+#             */
/*   Updated: 2023/01/19 14:50:27 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_write(char *dest, char *src, unsigned int n, unsigned int strlen);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	strlen;

	strlen = 0;
	while (src[strlen] != '\0')
	{
		strlen++;
	}
	ft_write(dest, src, size, strlen);
	return (strlen);
}

void	ft_write(char *dest, char *src, unsigned int size, unsigned int strlen)
{
	unsigned int	i;

	i = 0;
	if (size <= strlen)
	{
		while (i + 1 < size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	else if (size > strlen)
	{
		while (i < strlen)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
}
