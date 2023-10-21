/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 16:24:44 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/07 15:39:29 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_status;

void	ft_ctrld_handler(t_data *data)
{
	ft_printf_fd(1, "exit\n");
	ft_free_data(data);
	exit(0);
}

void	ft_sig_handler_cmd(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		g_exit_status = 130;
	}
	else if (sig == SIGQUIT)
	{
		write(1, "Quit (core dumped)\n", 19);
		g_exit_status = 131;
	}
}

void	ft_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_status = 130;
	}
}

bool	ft_all_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isspace(str[i]))
			return (false);
	}
	return (true);
}

void	ft_ctrld_handler_heredoc(char *delimiter, int line_count)
{
	ft_printf_fd(2, "racoonshell: warning: ");
	ft_printf_fd(2, "here-document at line %d ", line_count);
	ft_printf_fd(2, "delimited by end-of-file (wanted `%s')\n", delimiter);
}
