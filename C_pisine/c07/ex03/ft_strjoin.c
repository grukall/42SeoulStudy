/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:02:49 by seungule          #+#    #+#             */
/*   Updated: 2023/02/01 21:20:44 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	ft_putstrs(char **strs, char *result, int i, int index);
int	ft_putseps(char *sep, char *result, int index);
int	ft_strlen_check(char **strs, int size, char *sep);

int	ft_strlen_check(char **strs, int size, char *sep)
{
	int	i;
	int	strlen;

	i = 0;
	strlen = 0;
	while (i < size)
	{
		strlen += ft_strlen(strs[i]);
		if (i != size - 1)
			strlen += ft_strlen(sep);
		i++;
	}
	return (strlen);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*result;
	int		strlen;
	int		index;

	i = 0;
	index = 0;
	strlen = ft_strlen_check(strs, size, sep);
	result = (char *)malloc(sizeof(char) * (strlen + 1));
	if (result == 0)
		return (0);
	while (i < size)
	{
		index = ft_putstrs(strs, result, i, index);
		if (i != size - 1)
			index = ft_putseps(sep, result, index);
		i++;
	}
	result[index] = '\0';
	return (result);
}

int	ft_putstrs(char **strs, char *result, int i, int index)
{
	int	j;

	j = 0;
	while (strs[i][j] != '\0')
	{
		result[index] = strs[i][j];
		index++;
		j++;
	}
	return (index);
}

int	ft_putseps(char *sep, char *result, int index)
{
	int	j;

	j = 0;
	while (sep[j] != '\0')
	{
		result[index] = sep[j];
		index++;
		j++;
	}
	return (index);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
