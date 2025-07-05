/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:39:57 by seungule          #+#    #+#             */
/*   Updated: 2023/01/17 19:14:58 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);
void	change_int_tab(int *tab, int j);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				change_int_tab(tab, j);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	change_int_tab(int *tab, int j)
{
	int	temp;

	temp = tab[j];
	tab[j] = tab[j + 1];
	tab[j + 1] = temp;
}
