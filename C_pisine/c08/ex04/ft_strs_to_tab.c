/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:51:40 by seungule          #+#    #+#             */
/*   Updated: 2023/02/03 00:03:55 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str);

char	*ft_strdup(char *src)
{
	int		len;
	char	*str;

	len = 0;
	while (src[len] != '\0')
		len++;
	str = (char *)malloc(sizeof(char) * len + 1);
	len = 0;
	while (src[len] != '\0')
	{
		str[len] = src[len];
		len++;
	}
	str[len] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*pt;

	i = 0;
	pt = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (pt == NULL)
		return (NULL);
	while (i < ac)
	{
		pt[i].size = ft_strlen(av[i]);
		pt[i].str = av[i];
		pt[i].copy = ft_strdup(av[i]);
		i++;
	}
	pt[i].str = 0;
	return (pt);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
