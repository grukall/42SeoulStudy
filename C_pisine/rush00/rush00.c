/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:12:40 by seungule          #+#    #+#             */
/*   Updated: 2023/01/14 22:14:49 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush(int x, int y);
void	char_oi(int i, int y);
void	char_middle(int i, int y);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < y)
	{
		char_oi(i, y);
		while (j < x - 1)
		{
			char_middle(i, y);
			j++;
		}
		j = 1;
		char_oi(i, y);
		i++;
		ft_putchar('\n');
	}
}

void	char_oi(int i, int y)
{
	if (i == 0 || i == y - 1)
	{
		ft_putchar('o');
	}
	else
	{
		ft_putchar('|');
	}
}

void	char_middle(int i, int y)
{
	if (i == 0 || i == y - 1)
	{
		ft_putchar('-');
	}
	else
	{
		ft_putchar(' ');
	}
}
