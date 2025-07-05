/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:37:19 by seungule          #+#    #+#             */
/*   Updated: 2023/02/02 19:00:25 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
int		count_str(char **tab);

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	char	*temp;
	int		argc;

	i = 1;
	j = 1;
	argc = count_str(tab);
	while (i < argc - 1)
	{
		while (j < argc - 1)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		j = 1;
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			a = s1[i];
			b = s2[i];
			return ((int)(a - b));
		}
		i++;
	}
	return (0);
}

int	count_str(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
