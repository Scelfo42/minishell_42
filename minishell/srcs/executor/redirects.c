/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:17:59 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/07 16:35:06 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_close_redirect(t_data *data)
{
	if (data->infile_fd != -2)
	{
		if (data->infile_fd != -3)
			close(data->infile_fd);
		data->infile_fd = -2;
		dup2(data->stdin_copy, 0);
	}
	if (data->outfile_fd != -2)
	{
		close(data->outfile_fd);
		data->outfile_fd = -2;
		dup2(data->stdout_copy, 1);
	}
}

void	ft_which_redirect(t_data *data, int fd_in, int fd_out)
{
	if (data->infile_fd != -2)
		dup2(data->infile_fd, 0);
	else if (fd_in != -1)
		dup2(fd_in, 0);
	if (data->outfile_fd != -2)
		dup2(data->outfile_fd, 1);
	else if (fd_out != -1)
		dup2(fd_out, 1);
}

int	ft_redirect_handler(t_data *data, t_lexer *node)
{
	int		exit_status;
	int		i;
	char	**red;

	i = 0;
	exit_status = 0;
	red = node->red;
	while (red[i] && !exit_status)
	{
		if (!ft_strncmp(red[i], "<", 1) && red[i][1] != '<')
			ft_red_input(&red[i][1], data);
		else if (!ft_strncmp(red[i], "<<", 2))
			data->infile_fd = ft_heredoc(&red[i][2], data);
		else if (!ft_strncmp(red[i], ">", 1) && red[i][1] != '>')
			ft_red_output(&red[i][1], data, O_TRUNC);
		else if (!ft_strncmp(red[i], ">>", 2))
			ft_red_output(&red[i][2], data, O_APPEND);
		if (data->infile_fd == -1 || data->outfile_fd == -1)
			exit_status = 1;
		else if (data->infile_fd == -3)
			exit_status = 130;
		i++;
	}
	return (exit_status);
}
