/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:13:18 by seungule          #+#    #+#             */
/*   Updated: 2023/01/24 14:28:16 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;
	int	nope;

	i = 2;
	nope = 0;
	while (nb >= 2)
	{
		while (i <= nb / i)
		{
			if (nb % i == 0)
			{
				nope = 1;
				break ;
			}
			i++;
		}
		if (nope == 0)
			return (nb);
		nope = 0;
		i = 2;
		nb++;
	}
	return (2);
}
