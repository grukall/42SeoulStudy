/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_base_outside.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 00:19:22 by seungule          #+#    #+#             */
/*   Updated: 2023/02/02 05:38:19 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "info.h"
#include <stdio.h>

int		check1(char *buf, int check);
int		check2(char *buf, int check, t_map_info *map_inf);
int		check3(char *buf, int check, t_map_info *map_inf);
char	**ft_split(char *str, char *charset);
void	print_error(void);

void	check_outside(char *outside, t_map_info *map_inf)
{
	int	i;

	i = 0;
	while (outside[i] != '\0')
	{
		if (check3(&outside[i], 1, map_inf) == 0)
			print_error();
		i++;
	}
}

int	make_map_outside(char ***str, t_map_info *map_inf)
{
	char	*outside;
	int		check;
	int		size;

	outside = (char *)malloc(sizeof(char) * 1000000);
	size = 0;
	check = read(0, outside, 1000000);
	if (check == 0)
		print_error();
	while (outside[size] != '\n')
		size++;
	map_inf -> answer = outside[size - 1];
	map_inf -> block = outside[size - 2];
	map_inf -> dot = outside[size - 3];
	outside[check - 1] = '\0';
	outside += size + 1;
	check_outside(outside, map_inf);
	*str = ft_split(outside, "\n");
	return (1);
}
