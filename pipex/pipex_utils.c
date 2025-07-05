/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:13:28 by seungule          #+#    #+#             */
/*   Updated: 2023/08/16 19:03:13 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *errname)
{
	char	*temp;

	temp = strerror(errno);
	write(1, "pipex : ", 9);
	if (!errno)
		write(1, errname, ft_strlen(errname));
	else
	{
		if (errname && !ft_strncmp(errname, "pipe", 4))
			write(1, "pipe error: ", 13);
		write(1, temp, ft_strlen(temp));
		write(1, "\n", 1);
	}
	exit(1);
}

void	error_process(char *filename)
{
	char	*temp;

	if (errno == EFAULT)
		temp = "command not found";
	else
		temp = strerror(errno);
	write(2, "pipex : ", 9);
	write(2, temp, ft_strlen(temp));
	write(2, " : ", 4);
	write(2, filename, ft_strlen(filename));
	write(2, "\n", 1);
	exit(1);
}

char	**extract_path(char **envp)
{
	char	*temp;

	while (*envp)
	{
		temp = ft_strnstr(*envp++, "PATH", 5);
		if (temp != NULL)
			break ;
	}
	if (temp == NULL)
		return (NULL);
	while (*temp != '/')
		temp++;
	return (ft_split(temp, ':'));
}


void	input_argv_inf(struct arg_inf *arg, char **argv, char **envp)
{
	char	**path;
	int		result;

	path = extract_path(envp);
	arg->infilename = ft_strdup(argv[1]);
	if (arg->infilename == NULL)
		exit(1);
	arg->outfilename = ft_strdup(argv[4]);
	if (arg->outfilename == NULL)
		exit(1);
	arg->infile_command = ft_split(argv[2], ' ');
	if (arg->infile_command == NULL)
		exit(1);
	arg ->outfile_command = ft_split(argv[3], ' ');
	if (arg->outfile_command == NULL)
		exit(1);
	result = find_infile_command_file(arg, path);
	if (result == -1)
		exit(1);
	result = find_outfile_command_file(arg, path);
	if (result == -1)
		exit(1);
}
