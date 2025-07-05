/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:48:05 by seungule          #+#    #+#             */
/*   Updated: 2023/01/19 14:50:13 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n);
void	ft_write(char *dest, char *src, unsigned int n, unsigned int strlen);

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	strlen;

	strlen = 0;
	while (src[strlen] != '\0')
	{
		strlen++;
	}
	ft_write(dest, src, n, strlen);
	return (dest);
}

void	ft_write(char *dest, char *src, unsigned int n, unsigned int strlen)
{
	unsigned int	i;

	i = 0;
	if (n <= strlen)
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else if (n > strlen)
	{
		while (i < strlen)
		{
			dest[i] = src[i];
			i++;
		}
		while (i < n)
		{
			dest[i] = '\0';
			i++;
		}
	}
}
