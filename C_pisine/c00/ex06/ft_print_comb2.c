/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb9.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@49.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 9023/01/12 20:01:56 by seungule          #+#    #+#             */
/*   Updated: 2023/01/16 12:20:01 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	print_char(char	*num);

void	print_char(char	*num)
{
	if (num[1] == '9')
	{
		num[3] = num[0] + 1;
		num[4] = 0 + '0';
	}
	else
	{
		num[3] = num[0];
		num[4] = num[1] + 1;
	}
	while (num[3] <= '9')
	{
		while (num[4] <= '9')
		{
			write (1, num, 5);
			if (num[0] != '9' || num[1] != '8')
			{
				write (1, ", ", 2);
			}
			num[4]++;
		}
			num[4] = 0 + '0';
			num[3]++;
	}
}

void	ft_print_comb2(void)
{
	char	num[5];
	int		i;

	i = 0;
	while (i < 5)
	{
		num[i] = 0 + '0';
		i++;
	}
	num[2] = ' ';
	while (num[0] <= '9')
	{
		while (num[1] <= '9')
		{
			print_char(num);
			num[1]++;
		}
		num[1] = 0 + '0';
		num[0]++;
	}
}
