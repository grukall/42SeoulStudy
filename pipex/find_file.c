/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:38:13 by seungule          #+#    #+#             */
/*   Updated: 2023/08/16 17:51:20 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_infile_command_file(struct arg_inf *arg, char **path)
{
	char	*temp1;
	char	*temp2;
	int		result;

	if (!path)
		return (0);
	while (*path)
	{
		temp1 = ft_strjoin(*path++, "/");
		if (temp1 == NULL)
			return (-1);
		temp2 = ft_strjoin(temp1, arg->infile_command[0]);
		if (temp2 == NULL)
			return (-1);
		free(temp1);
		result = access(temp2, F_OK | X_OK);
		if (!result)
		{
			arg->infile_command_path = temp2;
			return (0);
		}
		free(temp2);
	}
	arg->infile_command_path = NULL;
	return (0);
}

int	find_outfile_command_file(struct arg_inf *arg, char **path)
{
	char	*temp1;
	char	*temp2;
	int		result;

	if (!path)
		return (0);
	while (*path)
	{
		temp1 = ft_strjoin(*path++, "/");
		temp2 = ft_strjoin(temp1, arg->outfile_command[0]);
		free(temp1);
		result = access(temp2, F_OK | X_OK);
		if (!result)
		{
			arg->outfile_command_path = temp2;
			return (0);
		}
		free(temp2);
	}
	arg->outfile_command_path = NULL;
	return (0);
}
