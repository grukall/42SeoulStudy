/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:43:15 by seungule          #+#    #+#             */
/*   Updated: 2023/01/19 14:51:32 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ch_to_num(unsigned char *ch);
char	change_int(int a);

void	ft_putstr_non_printable(char *str)
{
	char	*ch;

	ch = str;
	while (*ch)
	{
		if (*ch < 32 || *ch >= 127)
		{
			ch_to_num((unsigned char *)ch);
		}	
		else
		{
			write(1, ch, 1);
		}
		ch++;
	}
}

void	ch_to_num(unsigned char *ch)
{
	int		big;
	int		small;
	char	big_ch;
	char	small_ch;

	big = *ch / 16;
	small = *ch % 16;
	big_ch = change_int(big);
	small_ch = change_int(small);
	write(1, "\\", 1);
	write(1, &big_ch, 1);
	write(1, &small_ch, 1);
}

char	change_int(int a)
{
	char	b;

	if (a >= 10 && a <= 15)
	{
		b = a + 87;
	}
	else
	{
		b = a + '0';
	}
	return (b);
}
