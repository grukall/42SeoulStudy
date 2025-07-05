/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:48:18 by seungule          #+#    #+#             */
/*   Updated: 2023/02/01 21:32:42 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_check(int *puzzle, int i);
void	print_num(int *puzzle);
int		validcheck(int *puzzle, int i);

int	ft_ten_queens_puzzle(void)
{
	int	puzzle[11];
	int	count;

	count = 0;
	while (count < 10)
	{
		puzzle[count] = 0;
		count++;
	}
	puzzle[10] = 42;
	count = 0;
	while (count <= 9)
	{
		puzzle[0] = count;
		ft_check(&puzzle[0], 0);
		count++;
	}
	return (puzzle[10] - 42);
}

void	ft_check(int *puzzle, int i)
{
	int	num;

	num = 0;
	if (validcheck(puzzle, i))
	{
		if (*(puzzle + 1) >= 42)
		{
			print_num(puzzle - 9);
			*(puzzle + 1) += 1;
			return ;
		}
		while (num <= 9)
		{
			*(puzzle + 1) = num;
			ft_check(puzzle + 1, i + 1);
			num++;
		}
	}
	return ;
}

int	validcheck(int *puzzle, int i)
{
	int	*index;
	int	k;
	int	j;

	k = 1;
	j = 0;
	index = puzzle - i;
	while (j < i)
	{
		if (*index == *puzzle)
			return (0);
		index++;
		j++;
	}
	while (k <= i && (*puzzle - k >= 0 || *puzzle + k <= 9))
	{
		if (*(puzzle - k) == *puzzle - k || *(puzzle - k) == *puzzle + k)
			return (0);
		k++;
	}
	return (1);
}

void	print_num(int *puzzle)
{
	char	a;

	while (*puzzle < 42)
	{
		a = *puzzle + '0';
		write(1, &a, 1);
		puzzle++;
	}
	write(1, "\n", 1);
}

#include <stdio.h>
int main()
{
	printf("%d", ft_ten_queens_puzzle());
}
