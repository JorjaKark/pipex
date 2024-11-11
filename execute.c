/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:15:01 by mafferre          #+#    #+#             */
/*   Updated: 2024/08/05 12:15:03 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_path(char *env)
{
	char	*path;
	int		i;

	i = 0;
	path = "PATH=";
	while (env[i] && path[i])
	{
		if (env[i] != path[i])
			return (0);
		i++;
	}
	return (path[i] == '\0');
}

char	*get_paths(char *env_paths, char *cmd)
{
	auto int i = 0;
	auto char **paths = ft_split(env_paths, ':');
	auto char *path;
	auto char *cmd_path;
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		if (!path)
			error_checkers('n');
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (cmd_path && is_path_valid(cmd_path))
		{
			free_paths(paths);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

void	execute(char *argv, char **env)
{
	auto char **cmd = ft_split(argv, ' ');
	auto int i = 0;
	auto char *valid_path = NULL;
	auto char *paths = NULL;
	ft_check_null(cmd);
	while (env[i])
	{
		if (is_path(env[i]))
		{
			paths = env[i];
			break ;
		}
		i++;
	}
	ft_check_path(paths, cmd);
	valid_path = get_paths(paths, cmd[0]);
	ft_check_valid(valid_path, cmd);
	if (execve(valid_path, cmd, env) == -1)
	{
		free_paths(cmd);
		free(valid_path);
	}
}
