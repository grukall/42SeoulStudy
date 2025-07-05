/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:18:11 by seungule          #+#    #+#             */
/*   Updated: 2023/02/02 21:29:42 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str);
void    calculate(int one, int two, char operator);
int	plus(int one,int two);
int	minus(int one,int two);
int	mok(int one,int two);
int	gop(int one,int two);
int	nanu(int one,int two);
int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if ((argv[2] != '+'
		&& argv[2][0] != '-'
		&& argv[2][0] != '/'
		&& argv[2][0] != '*'
		&& argv[2][0] != '%')
		|| argv[2][0] != '\0')
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (argv[3][0] == '0' && argv[2][0] == '/')
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	else if(argv[3][0] == '0' && argv[2][0] == '%')
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	calculate(ft_atoi(argv[1]), ft_atoi(argv[3]), argv[2][0]);
}

void    calculate(int one, int two, char operator)
{
	void	(*f)[5](int	,int);
	f[0] = plus;
	f[1] = minus;
	f[2] = mok;
	f[3] = gop;
	f[4] = nanu;

	if (operator == '+')
		f[0](one, two);
	if (operator == '-')
		f[1](one, two);
	if (operator == '/')
		f[2](one, two);
	if (operator == '*')
		f[3](one, two);
	if (operator == '%')
		f[4](one, two);
	write(1, "\n", 1);
}
