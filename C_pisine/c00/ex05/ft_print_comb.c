/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:16:55 by seungule          #+#    #+#             */
/*   Updated: 2023/01/16 12:18:16 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);

void	ft_print_comb(void)
{
	char	num[3];

	num[0] = 0 + '0';
	num[1] = 1 + '0';
	num[2] = 2 + '0';
	while (num[0] <= '7')
	{
		num[1] = num[0] + 1;
		while (num[1] <= '8')
		{
			num[2] = num[1] + 1;
			while (num[2] <= '9')
			{
				write (1, num, 3);
				if (num[0] < '7')
				{
					write (1, ", ", 2);
				}
				num[2]++;
			}
			num[1]++;
		}
	num[0]++;
	}
}
