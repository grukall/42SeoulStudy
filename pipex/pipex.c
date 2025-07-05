/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:40:10 by seungule          #+#    #+#             */
/*   Updated: 2023/08/16 19:00:14 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	struct arg_inf	arg;

	if (argc != 5)
		error("argument is incorrect");
	input_argv_inf(&arg, argv, envp);
	pipex(&arg);
	exit(0);
}

void	pipex(struct arg_inf *arg)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;
	int		status;

	if (pipe(fd) == -1)
		error("pipe");
	pid = fork();
	if (!pid)
		child(fd, arg);
	else
	{
		pid2 = fork();
		if (!pid2)
			child2(fd, arg);
		else
		{
			close(fd[READ_FILE]);
			close(fd[WRITE_FILE]);
			waitpid(pid, NULL, 0);
			waitpid(pid2, &status, 0);
			if (status)
				exit(1);
		}
	}
}

void	child(int fd[2], struct arg_inf *arg)
{
	int		fd_infile;

	close(fd[READ_FILE]);
	fd_infile = open(arg->infilename, O_RDONLY);
	if (fd_infile == -1)
		error_process(arg->infilename);
	if (dup2(fd_infile, STDIN_FILENO) == -1)
		error_process(NULL);
	if (dup2(fd[WRITE_FILE], STDOUT_FILENO) == -1)
		error_process(NULL);
	close(fd_infile);
	close(fd[WRITE_FILE]);
	fd_infile = execve(arg->infile_command_path, arg->infile_command, NULL);
	if (fd_infile == -1)
		error_process(arg->infile_command[0]);
}

void	child2(int fd[2], struct arg_inf *arg)
{
	int		fd_outfile;

	close(fd[WRITE_FILE]);
	fd_outfile = open(arg->outfilename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_outfile == -1)
		error_process(arg->outfilename);
	if (dup2(fd[READ_FILE], STDIN_FILENO) == -1)
		error_process(NULL);
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		error_process(NULL);
	close(fd_outfile);
	close(fd[READ_FILE]);
	fd_outfile = execve(arg->outfile_command_path, arg->outfile_command, NULL);
	if (fd_outfile == -1)
		error_process(arg->outfile_command[0]);
}
