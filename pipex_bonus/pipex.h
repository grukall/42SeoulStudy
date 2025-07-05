/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:08:30 by seungule          #+#    #+#             */
/*   Updated: 2023/08/08 15:26:08 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define READ_FILE	0
# define WRITE_FILE	1

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct arg_inf
{
	char	*infilename;
	char	*outfilename;
	char	**command;
	char	*command_path;
}t_arg_inf;

void	pipex(int argc, char **argv, char **path);
void	error(char *errorname);
void	error_process(char *filename);
char	**extract_path(char **envp);
int		find_command(struct arg_inf *arg, char **path);
void	heredoc(t_arg_inf *arg);
int		**before_pipex(t_arg_inf *arg, int *argc, char **argv, pid_t **pid);

#endif