/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:13:28 by seungule          #+#    #+#             */
/*   Updated: 2023/08/03 17:12:28 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *errorname)
{
	write(1, "pipex : ", 9);
	write(1, errorname, ft_strlen(errorname));
	write(1, "\n", 1);
	exit(1);
}
void	error_process(char *filename)
{
	char	*temp;

	if (errno == EFAULT)
		temp = ft_strdup("command not found");
	else
		temp = strerror(errno);
	write(2, "pipex : ", 9);
	write(2, temp, ft_strlen(temp));
	write(2, " : ", 4);
	write(2, filename, ft_strlen(filename));
	write(2, "\n", 1);
	getchar();
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
