/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:40:00 by seungule          #+#    #+#             */
/*   Updated: 2023/02/02 06:29:02 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "info.h"

char	**ft_split(char *str, char *charset);
void	ft_bsq(char **map, t_map_info map_inf);
int		map_str(t_map_info *map_inf, char **argv);
void	make_map_base(int size, char **argv, char ***str);
char	*ft_putnbr_base(int nbr, char *base);
int		ft_strlen(char *str);
void	map_xy(char **str, t_map_info *map_inf);
int		check1(char *buf, int check);
int		check2(char *buf, int check, t_map_info *map_inf);
int		make_map_outside(char ***str, t_map_info *map_inf);
void	map_str_get_map(t_map_info *map_inf, char **argv);
void	print_error(void);

int	main(int argc, char **argv)
{
	int			size;
	char		**str;
	int			fd;
	t_map_info	map_inf;

	if (argc < 1 || argc > 2)
		return (0);
	else if (argc == 1)
	{
		size = make_map_outside(&str, &map_inf);
		if (size == 0)
			print_error();
	}
	else
	{
		fd = open(argv[1], O_RDWR);
		if (fd < 0)
			print_error();
		size = map_str(&map_inf, argv);
		if (size == 0)
			print_error();
		make_map_base(size, argv, &str);
	}
	map_xy(str, &map_inf);
	ft_bsq(str, map_inf);
}

int	map_str(t_map_info *map_inf, char **argv)
{
	char	buf[2];
	int		check;
	int		size;

	size = 0;
	buf[1] = '\0';
	map_str_get_map(map_inf, argv);
	check = read(3, buf, 1);
	while (check != 0)
	{
		if (check2(buf, check, map_inf) == 0)
			return (0);
		check = read(3, buf, 1);
		size++;
	}
	close(3);
	return (size);
}

void	map_str_get_map(t_map_info *map_inf, char **argv)
{
	int		size;
	char	*first_line;
	char	buf[2];
	int		check;

	size = 0;
	buf[1] = '\0';
	check = read(3, buf, 1);
	while (buf[0] != '\n')
	{
		check = read(3, buf, 1);
		if (check1(buf, check) == 0)
			print_error();
		size++;
	}
	first_line = (char *)malloc(sizeof(char) * size);
	close(3);
	open(argv[1], O_RDWR);
	read(3, first_line, size);
	map_inf -> answer = first_line[size - 1];
	map_inf -> block = first_line[size - 2];
	map_inf -> dot = first_line[size - 3];
	free(first_line);
}

void	make_map_base(int size, char **argv, char ***str)
{
	char	*arr;
	int		fd;
	int		check;
	char	buf[1];

	arr = (char *)malloc(sizeof(char) * size);
	if (arr == NULL)
		print_error();
	fd = open(argv[1], O_RDWR);
	while (buf[0] != '\n')
		check = read(fd, buf, 1);
	check = read(fd, arr, size - 1);
	arr[size - 1] = '\0';
	*str = ft_split(arr, "\n");
	close(fd);
}

void	map_xy(char **str, t_map_info *map_inf)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (str[0][x])
		x++;
	map_inf->x = x;
	while (str[y])
		y++;
	map_inf->y = y;
}
