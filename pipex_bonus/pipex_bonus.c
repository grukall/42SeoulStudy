/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:40:10 by seungule          #+#    #+#             */
/*   Updated: 2023/08/08 16:47:42 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**path;

	if (argc < 5)
		error("argument is incorrect");
	path = extract_path(envp);
	pipex(argc, argv, path);
	unlink("./temp.txt");
}

void	pipex(int argc, char **argv, char **path)
{
	struct arg_inf	arg;
	int				**fd_process;
	int				i;
	int				k;
	pid_t			*pid;

	fd_process = before_pipex(&arg, &argc, argv, &pid);
	i = -1;

	while (++i < argc - 4)
	{
		int fd_in;
		int	fd_out;
		int fd_file;
		int result;

		if (pipe(fd_process[i]) == -1)
			error("pipe failed");
		if (!ft_strncmp(arg.infilename, "temp.txt", 7))
			k = i + 3;
		else
			k = i + 2;
		pid[i] = fork();
		if (i == 0 && !pid[i])
		{
			close(fd_process[i][READ_FILE]);
			fd_file = open(arg.infilename, O_RDONLY);
			fd_in = dup2(fd_file, STDIN_FILENO);
			close(fd_file);
			fd_out = dup2(fd_process[i][WRITE_FILE], STDOUT_FILENO);
			close(fd_process[i][WRITE_FILE]);
			arg.command = ft_split(argv[k], ' ');
			find_command(&arg, path);
			result = execve(arg.command_path, arg.command, NULL);
			if (result == -1)
				error_process(arg.command[0]);
		}
		else if (!pid[i])
		{
			fd_in = dup2(fd_process[i - 1][READ_FILE], STDIN_FILENO);
			close(fd_process[i - 1][READ_FILE]);
			fd_out = dup2(fd_process[i][WRITE_FILE], STDOUT_FILENO);
			close(fd_process[i][WRITE_FILE]);
			arg.command = ft_split(argv[k], ' ');
			find_command(&arg, path);
			result = execve(arg.command_path, arg.command, NULL);
			if (result == -1)
				error_process(arg.command[0]);
		}
		else
			waitpid(pid[i], NULL, WNOHANG);
		close(fd_process[i][WRITE_FILE]);
	}
	if (!ft_strncmp(arg.infilename, "temp.txt", 7))
		k = i + 3;
	else
		k = i + 2;
	pid[argc - 4] = fork();
	if (!pid[argc - 4])
	{
		int fd_in;
		int	fd_out;
		int fd_file;
		int result;

		close(fd_process[i - 1][WRITE_FILE]);
		fd_file = open(arg.outfilename, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		fd_out = dup2(fd_file, STDOUT_FILENO);
		close(fd_file);
		fd_in = dup2(fd_process[i - 1][READ_FILE], STDIN_FILENO);
		close(fd_process[i - 1][READ_FILE]);
		arg.command = ft_split(argv[k], ' ');
		find_command(&arg, path);
		result = execve(arg.command_path, arg.command, NULL);
		if (result == -1)
			error_process(arg.command[0]);
	}
	int j = 1;
	int status;
	while(j < 3)
	{
		waitpid(pid[j++], &status, 0);
		printf("%d번째 pid 회수 완료 %d\n", j, status);
	}
}

void	heredoc(struct arg_inf *arg)
{
	char	*temp;
	int		fd;
	int		pid;

	pid = fork();
	if (!pid)
	{
		fd = open("temp.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);
		while (1)
		{
			write(1, "heredoc> ", 9);
			temp = get_next_line(0);
			if (temp == NULL)
				error_process("get_next_line");
			if (!ft_strncmp(temp, arg->infilename, ft_strlen(arg->infilename)))
				break ;
			write(fd, temp, ft_strlen(temp));
		}
		close(fd);
		exit(0);
	}
	else
		waitpid(pid, NULL, 0);
	free(arg->infilename);
	arg->infilename = NULL;
	arg->infilename = ft_strdup("temp.txt");
}
