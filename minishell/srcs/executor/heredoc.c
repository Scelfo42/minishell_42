/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:10:36 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/07 16:34:05 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

static void	ft_set_and_kill(int pid)
{
	static int	pid_to_kill = 0;

	if (pid_to_kill)
	{
		ft_putchar_fd('\0', 0);
		kill(pid_to_kill, SIGKILL);
		pid_to_kill = 0;
	}
	else if (pid)
		pid_to_kill = pid;
}

static void	ft_handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ft_set_and_kill(0);
		g_exit_status = 130;
	}
}

static void	ft_heredoc_init(char *delimiter, int fd)
{
	char	*line;
	int		delimiter_len;
	int		line_count;

	delimiter_len = ft_strlen(delimiter);
	line_count = 1;
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (!line)
		{
			ft_ctrld_handler_heredoc(delimiter, line_count);
			break ;
		}
		else if (!ft_strncmp(line, delimiter, delimiter_len) && \
			line[delimiter_len] == '\n')
			break ;
		ft_putstr_fd(line, fd);
		free(line);
		line = NULL;
		line_count++;
	}
	free(line);
	line = NULL;
}

static int	ft_heredoc_child(t_data *data, char *delimiter, int fd)
{
	ft_heredoc_init(delimiter, fd);
	ft_free_lexer(data);
	data->env_matrix = ft_free_matrix(data->env_matrix);
	ft_free_data(data);
	exit(0);
}

int	ft_heredoc(char *delimiter, t_data *data)
{
	char	*path;
	int		fd;
	int		pid;
	int		exit_status;

	g_exit_status = 0;
	path = ".heredoc";
	unlink(path);
	if (data->infile_fd > -1)
		close(data->infile_fd);
	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	pid = fork();
	ft_set_and_kill(pid);
	if (pid == 0)
		ft_heredoc_child(data, delimiter, fd);
	signal(SIGINT, ft_handle_sigint);
	waitpid(pid, &exit_status, 0);
	close(fd);
	if (g_exit_status == 130)
		return (-3);
	fd = open(path, O_RDONLY);
	return (fd);
}
