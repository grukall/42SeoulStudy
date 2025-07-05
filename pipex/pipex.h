/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:08:30 by seungule          #+#    #+#             */
/*   Updated: 2023/08/16 18:55:56 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define WRITE_FILE	1
# define READ_FILE	0
# define BUFFER_SIZE 1000

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "./libft/libft.h"

typedef struct arg_inf
{
	char	*infilename;
	char	**infile_command;
	char	*infile_command_path;
	char	*outfilename;
	char	**outfile_command;
	char	*outfile_command_path;
	char	*error_string;
}t_arg_inf;

void	pipex(t_arg_inf *arg);
void	error(char *errname);
void	error_process(char *filename);
char	**extract_path(char **envp);
int		find_infile_command_file(struct arg_inf *arg, char **path);
int		find_outfile_command_file(struct arg_inf *arg, char **path);
void	input_argv_inf(struct arg_inf *arg, char **argv, char **envp);
void	child(int fd[2], struct arg_inf *arg);
void	child2(int fd[2], struct arg_inf *arg);

#endif