/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 22:53:12 by seungule          #+#    #+#             */
/*   Updated: 2023/01/14 20:51:02 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	ft_print(int *a, int n, int index, int num);
void	ft_coma_space(void);
void	ft_print_char(int *a, int n);

void	ft_print_combn(int n)
{
	int	a[9];
	int	i;

	i = 0;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
	ft_print(a, n, 0, 0);
}

void	ft_coma_space(void)
{
	write(1, ", ", 2);
}

void	ft_print_char(int *a, int n)
{	
	char	b[9];
	int		i;

	i = 0;
	while (i < n)
	{
		b[i] = a[i] + '0';
		i++;
	}
	write (1, b, n);
}

void	ft_print(int *a, int n, int index, int num)
{
	if (index < n - 1)
	{
		a[index] = num;
	}
	if (index == n - 1)
	{
		a[index] = num;
		ft_print_char(a, n);
		ft_coma_space();
		return ;
	}
	while (num <= 10 - n + index)
	{
		ft_print(a, n, index + 1, num + 1);
		num++;
	}
	num = 0;
}
