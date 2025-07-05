/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:42:25 by seungule          #+#    #+#             */
/*   Updated: 2023/02/03 00:05:33 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_putnbr(int nb);
void	change_char(char *a, int num_size);
void	print_char(char *a, int sign, int i);
void	put_num_to_str(char *a, int nb, int i, int sign);

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;
	int		j;

	j = -1;
	i = 0;
	while (1)
	{
		if (par[i].str == 0)
			break ;
		while (par[i].str[++j] != '\0')
			write(1, &par[i].str[j], 1);
		write(1, "\n", 1);
		j = -1;
		ft_putnbr(par[i].size);
		while (par[i].str[++j] != '\0')
			write(1, &par[i].str[j], 1);
		j = -1;
		write(1, "\n", 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char			a[10];
	int				i;
	int				sign;

	i = 0;
	sign = 1;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb < 0)
	{
		sign = -1;
		nb = nb * -1;
	}
	put_num_to_str(a, nb, i, sign);
}

void	change_char(char *a, int num_size)
{
	int		temp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < num_size)
	{
		while (j < num_size - i)
		{
			temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_char(char *a, int sign, int i)
{
	if (sign < 0)
	{
		write (1, "-", 1);
		write (1, a, i + 1);
	}
	else
	{
		write (1, a, i + 1);
	}
}

void	put_num_to_str(char *a, int nb, int i, int sign)
{
	while (i < 10)
	{
		a[i] = nb % 10 + '0';
		nb = nb / 10;
		if (nb == 0)
		{
			change_char(a, i + 1);
			print_char(a, sign, i);
			break ;
		}
		i++;
	}
	write(1, "\n", 1);
}
