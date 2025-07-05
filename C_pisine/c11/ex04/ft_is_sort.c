/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:41 by seungule          #+#    #+#             */
/*   Updated: 2023/02/02 18:59:33 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i + 2 < length)
	{
		if (f(tab[i], tab[i + 1]) > 0 && f(tab[i + 1], tab[i + 2]) < 0)
			return (0);
		if (f(tab[i], tab[i + 1]) < 0 && f(tab[i + 1], tab[i + 2]) > 0)
			return (0);
		i++;
	}
	return (1);
}
