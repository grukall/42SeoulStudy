/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:38:13 by seungule          #+#    #+#             */
/*   Updated: 2023/08/08 15:26:31 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	find_command(struct arg_inf *arg, char **path)
{
	char	*temp1;
	char	*temp2;
	int		result;

	while (*path)
	{
		temp1 = ft_strjoin(*path++, "/");
		temp2 = ft_strjoin(temp1, arg->command[0]);
		free(temp1);
		result = access(temp2, F_OK | X_OK);
		if (!result)
		{
			arg->command_path = temp2;
			return (0);
		}
		free(temp2);
	}
	arg->command_path = NULL;
	return (0);
}

int	**before_pipex(t_arg_inf *arg, int *argc, char **argv, pid_t **pid)
{
	int		**fd_process;
	int		i;

	arg->outfilename = ft_strdup(argv[*argc - 1]);
	if (!ft_strncmp(argv[1], "here_doc", 7))
	{
		arg->infilename = ft_strdup(argv[2]);
		heredoc(arg);
		(*argc)--;
	}
	else
		arg->infilename = ft_strdup(argv[1]);
	*pid = (pid_t *)malloc(sizeof(pid_t) * (*argc - 3));
	if (!pid)
		error("mallloc failed");
	fd_process = (int **)malloc(sizeof(int *) * (*argc - 4));
	if (!fd_process)
		error("mallloc failed");
	i = 0;
	while (i < *argc - 4)
		fd_process[i++] = (int *)malloc(sizeof(int) * 2);
	return (fd_process);
}