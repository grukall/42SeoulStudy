/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:34:57 by seungule          #+#    #+#             */
/*   Updated: 2023/09/24 16:30:36 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parsing(t_push_swap *ps, char **argv)
{
	char	**result;
	char	*temp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (argv[++j])
	{
		temp = ft_strtrim(argv[j], " ");
		if (!temp || temp[0] == '\0')
			error(ps);
		result = ft_split(temp, ' ');
		if (!result)
			error(ps);
		i = push_stack(ps, result, i);
		free(result);
		free(temp);
	}
}

int	check_len(char **argv)
{
	int		i;
	int		j;
	int		index;
	char	*temp;
	char	**result;

	i = 1;
	index = 0;
	while (argv[i])
	{
		j = 0;
		temp = ft_strtrim(argv[i], " ");
		if (!temp || temp[0] == '\0')
			error(NULL);
		result = ft_split(temp, ' ');
		if (!result)
			error(NULL);
		while (result[j++])
			index++;
		free(temp);
		free(result);
		i++;
	}
	return (index);
}
