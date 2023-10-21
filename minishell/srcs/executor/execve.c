/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:18:11 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/04 14:18:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_execve(char *cmd_path, char **cmd_args, t_data *data)
{
	int	exit_status;
	int	pid;

	exit_status = 0;
	pid = fork();
	if (!pid)
	{
		if (execve(cmd_path, cmd_args, data->env_matrix) == -1)
		{
			ft_free_lexer(data);
			data->env_matrix = ft_free_matrix(data->env_matrix);
			ft_free_data(data);
			exit(127);
		}
		ft_free_lexer(data);
		data->env_matrix = ft_free_matrix(data->env_matrix);
		ft_free_data(data);
		exit(0);
	}
	waitpid(pid, &exit_status, 0);
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	else if (WIFSIGNALED(exit_status))
		exit_status = 130;
	return (exit_status);
}
