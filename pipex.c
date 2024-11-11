/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:15:11 by mafferre          #+#    #+#             */
/*   Updated: 2024/08/05 12:15:12 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, int *fd, char **env)
{
	auto int file1;
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		error('f');
	dup2(fd[1], 1);
	dup2(file1, 0);
	close(fd[0]);
	close(file1);
	execute(argv[2], env);
}

void	parent(char **argv, int *fd, char **env)
{
	auto int file2;
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 == -1)
		error('f');
	dup2(fd[0], 0);
	dup2(file2, 1);
	close(fd[1]);
	close(file2);
	execute(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
		error('a');
	if (pipe(p_fd) == -1)
		error('p');
	pid = fork();
	if (pid < 0)
	{
		error('p');
	}
	if (pid == 0)
	{
		child(argv, p_fd, env);
	}
	else
	{
		parent(argv, p_fd, env);
	}
	return (0);
}
