/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:18:22 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/07 15:40:27 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

int	ft_exec_no_pipe(t_data *data, t_lexer *node, int fd_in, int fd_out)
{
	int		exit_status;

	exit_status = ft_redirect_handler(data, node);
	if (!exit_status)
	{
		ft_which_redirect(data, fd_in, fd_out);
		exit_status = ft_exec(data, node->wrd);
	}
	ft_close_redirect(data);
	return (exit_status);
}

void	ft_close_fds(int fd_in, int fd_out)
{
	if (fd_in != -1 && fd_in != -2)
		close(fd_in);
	if (fd_out != -1 && fd_out != -2)
		close(fd_out);
}

int	ft_handle_pipes(t_data *data, t_lexer *node, int fd_in, int fd_out)
{
	int	exit_status;
	int	pid;

	pid = fork();
	if (!pid)
	{
		exit_status = ft_redirect_handler(data, node);
		if (!exit_status)
		{
			ft_which_redirect(data, fd_in, fd_out);
			exit_status = ft_exec(data, node->wrd);
		}
		ft_close_fds(fd_in, fd_out);
		ft_free_lexer(data);
		data->env_matrix = ft_free_matrix(data->env_matrix);
		ft_free_data(data);
		exit(exit_status);
	}
	waitpid(pid, &exit_status, 0);
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	return (exit_status);
}

int	ft_exec_pipe(t_data *data, t_lexer *node, int fd_out)
{
	int	fd[2];

	if (!node->next)
	{
		fd[0] = data->stdin_copy;
		fd[1] = -1;
	}
	else
	{
		if (pipe(fd) == -1)
			perror("pipe");
		ft_exec_pipe(data, node->next, fd[1]);
	}
	if (fd[1] != -1)
		close(fd[1]);
	return (ft_handle_pipes(data, node, fd[0], fd_out));
}

int	ft_choose_exec(t_data *data)
{
	int	exit_status;

	signal(SIGINT, ft_sig_handler_cmd);
	signal(SIGQUIT, ft_sig_handler_cmd);
	data->env_matrix = ft_list_to_matrix(data->env);
	exit_status = 0;
	if (!data->lexer->next)
		exit_status = ft_exec_no_pipe(data, data->lexer, 0, 1);
	else
		exit_status = ft_exec_pipe(data, data->lexer, 1);
	data->env_matrix = ft_free_matrix(data->env_matrix);
	if (g_exit_status != 0)
	{
		exit_status = g_exit_status;
		g_exit_status = 0;
	}
	return (exit_status);
}
