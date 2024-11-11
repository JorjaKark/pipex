/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafferre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:02:02 by mafferre          #+#    #+#             */
/*   Updated: 2024/08/13 15:02:04 by mafferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char c)
{
	if (c == 'c')
	{
		write(STDERR_FILENO, "Error: Command not found\n", 25);
		exit(0);
	}
	else if (c == 'f')
	{
		write(STDERR_FILENO, "Error: No such file or directory\n", 33);
		exit(2);
	}
	else if (c == 'a')
	{
		write(STDERR_FILENO, "Error: Invalid number of variables\n", 36);
		exit(3);
	}
	exit(1);
	return ;
}

void	error_checkers(char c)
{
	if (c == 'n')
	{
		write(STDERR_FILENO, "Error: Memory allocation has failed \n", 37);
	}
	else if (c == 'p')
	{
		write(STDERR_FILENO, "Error: PATH= not found\n", 24);
	}
	else if (c == 'v')
	{
		write(STDERR_FILENO, "Error: Command not found\n", 25);
		exit(0);
	}
	exit(1);
	return ;
}
