/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:27:07 by seungule          #+#    #+#             */
/*   Updated: 2023/01/14 19:38:14 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		while (j < size - i - 1)
		{
			temp = tab[j];
			tab[j] = tab[j + 1];
			tab[j + 1] = temp;
			j++;
		}
		j = 0;
		i++;
	}
}
