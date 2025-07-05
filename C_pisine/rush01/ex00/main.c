/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:32:53 by seungule          #+#    #+#             */
/*   Updated: 2023/01/22 17:14:32 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	char_to_int(int *col_row, char **argv);
int		valid_check(char **argv);
int		main(int argc, char **argv)
{
	int	col_row[16];   //입력받은 인자를 저장할 int형 배열
	int	valid;

	valid = 0;
	if (argc != 2)   //입력받은 인자가 1개가 아니라면 오류 출력후 0리턴
	{
		write(1, "Error\n", 6);
		return (0);
	}
	valid = valid_check(argv); //입력받는 인자가 규칙에 맞지 않는 입력 값이라면 오류 출력
	if (valid)
		char_to_int(col_row, argv);
	else
	{	
		write(1, "Error\n", 6);
		return (0);
	}
	ft_skyscraper(col_row);
}

int	valid_check(char **argv)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (argv[1][check])
		check++;
	if (check != 31)
		return (0);
	while (argv[1][i])
	{
		if (i % 2 == 0 && (argv[1][i] < '0' || argv[1][i] > '4'))
			return (0);
		else if (i % 2 == 1 && argv[1][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
void    char_to_int(int *col_row, char **argv)
{
	int argv_i;
	int col_row_i;

	argv_i = 0;
	col_row_i = 0;
	while(argv[1][argv_i])
	{
		if(argv_i % 2 == 0)
		{
			col_row[col_row_i] = argv[1][argv_i] - '0';
			col_row_i++;
		}
		argv_i++;
	}
}
