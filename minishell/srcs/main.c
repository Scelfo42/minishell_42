/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:17:00 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/07 15:31:05 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

static int	ft_shell(t_data *data)
{
	int	exit_status;

	ft_miniputstr_fd(data->prompt, data->history_fd);
	add_history(data->prompt);
	data->lexer = ft_init_lexer();
	exit_status = ft_parser(data);
	return (exit_status);
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	int		exit_status;

	(void)av;
	if (ac > 1)
		ft_ac_error();
	data = ft_init_data(envp);
	while (1)
	{
		signal(SIGINT, ft_sig_handler);
		signal(SIGQUIT, SIG_IGN);
		data->prompt = readline("🦝 racoonshell $> ");
		if (!data->prompt)
			ft_ctrld_handler(data);
		if (!*data->prompt || ft_all_spaces(data->prompt))
			continue ;
		exit_status = ft_shell(data);
		if (!exit_status)
			exit_status = ft_choose_exec(data);
		data->lexer = ft_free_lexer(data);
		data->exit_status = exit_status;
	}
	return (ft_free_data(data));
}
