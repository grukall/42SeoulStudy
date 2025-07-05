/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:16:55 by seungule          #+#    #+#             */
/*   Updated: 2023/01/18 17:39:36 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (str[i] || i == 0)
	{
		if (str[i] == to_find[0] || to_find[0] == '\0')
		{
			j = i;
			k = 0;
			while (to_find[k])
			{
				if (str[j] != to_find[k])
					break ;
				j++;
				k++;
			}
			if (to_find[k] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
