/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:16:50 by seungule          #+#    #+#             */
/*   Updated: 2023/01/15 20:37:58 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while(*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	valid_check(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	validation;

	i = 0;
	nbr = 0;
	validation = valid_check(str);
	while (str[i] >= '0' && str[i] <= '9' && validation)
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;
	if (argc == 3)
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
		if ((x > 0 && x <= 2147483647) && (y > 0 && y <= 2147483647))
			rush(x, y);
		else
			ft_putstr("Invaild input numbers\n");
	}
	else
		ft_putstr("Invalid input numbers\n");
	return (0);
}
