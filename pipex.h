/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:15:38 by mafferre          #+#    #+#             */
/*   Updated: 2024/08/05 12:15:39 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

//main.c
void	parent(char **argv, int *fd, char **env);
void	child(char **argv, int *fd, char **env);

//execute.c
int		is_path(char *env);
char	*get_paths(char *env_paths, char *cmd);
void	execute(char *argv, char **env);

//utils.c
void	error(char c);
void	error_checkers(char c);
int		is_path_valid(char *path);
void	free_paths(char **paths);

//checks.c
void	ft_check_null(char **cmd);
void	ft_check_path(char *paths, char **cmd);
void	ft_check_valid(char *valid_path, char **cmd);

#endif
