/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:51:30 by seungule          #+#    #+#             */
/*   Updated: 2023/02/02 19:00:56 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_str(char **tab);

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if (cmp(tab[j], tab[j + 1]) > 0)
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

int	count_str(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
