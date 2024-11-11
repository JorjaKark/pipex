/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:05:26 by mafferre          #+#    #+#             */
/*   Updated: 2024/08/05 13:05:27 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_null(char **cmd)
{
	if (cmd[0] == NULL)
	{
		free_paths(cmd);
		error_checkers('n');
	}
}

void	ft_check_path(char *paths, char **cmd)
{
	if (!paths)
	{
		free_paths(cmd);
		error_checkers('p');
	}
}

void	ft_check_valid(char *valid_path, char **cmd)
{
	if (!valid_path)
	{
		free_paths(cmd);
		error_checkers('v');
	}
}
