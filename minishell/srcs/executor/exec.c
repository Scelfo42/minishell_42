/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:18:16 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/08 15:57:32 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_split_path(t_list *env)
{
	char	**splitted_path;
	t_list	*tmp;

	tmp = env;
	splitted_path = NULL;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "PATH"))
			break ;
		tmp = tmp->next;
	}
	if (tmp)
		splitted_path = ft_split(tmp->content, ':');
	return (splitted_path);
}

bool	ft_ispath_set(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "PATH"))
			break ;
		tmp = tmp->next;
	}
	if (tmp)
		return (true);
	return (false);
}

static int	ft_search_in_path(char **cmd_mat, t_data *data)
{
	char	**env;
	char	*cmd_path;
	char	*tmp;
	int		exit_status;
	int		i;

	i = -1;
	exit_status = 127;
	if (ft_ispath_set(data->env) && cmd_mat[0] && *cmd_mat[0])
	{
		env = ft_split_path(data->env);
		while (env[++i] && exit_status == 127)
		{
			tmp = ft_strjoin(env[i], "/");
			cmd_path = ft_strjoin(tmp, cmd_mat[0]);
			if (!access(cmd_path, X_OK))
				exit_status = ft_execve(cmd_path, cmd_mat, data);
			free(tmp);
			free(cmd_path);
		}
		ft_free_matrix(env);
	}
	if (exit_status == 127)
		ft_printf_fd(2, "racoonshell: %s: command not found\n", cmd_mat[0]);
	return (exit_status);
}

static int	ft_executable(char **cmd, t_data *data)
{
	int	exit_status;

	exit_status = 126;
	if ((*cmd[0] == '/' || *cmd[0] == '.') && \
		cmd[0][ft_strlen(cmd[0]) - 1] != '/' && \
		!access(cmd[0], F_OK) && ft_isdirectory(cmd[0]) == -1)
	{
		if (!access(cmd[0], X_OK))
			exit_status = ft_execve(cmd[0], cmd, data);
		else
			ft_printf_fd(2, "racoonshell: %s: Permission denied\n", cmd[0]);
	}
	else if (!ft_strchr(cmd[0], '/'))
		exit_status = ft_search_in_path(cmd, data);
	else if (!ft_isdirectory(cmd[0]))
		ft_printf_fd(2, "racoonshell: %s: Is a directory\n", cmd[0]);
	else
	{
		ft_printf_fd(2, "racoonshell: %s: No such file or directory\n", cmd[0]);
		exit_status++;
	}
	return (exit_status);
}

int	ft_exec(t_data *data, char **wrd)
{
	int		exit_status;

	exit_status = 0;
	if (!wrd[0])
		return (exit_status);
	else if (!ft_strcmp(wrd[0], "echo"))
		exit_status = ft_echo(&wrd[1]);
	else if (!ft_strcmp(wrd[0], "cd"))
		exit_status = ft_cd(data);
	else if (!ft_strcmp(wrd[0], "pwd"))
		exit_status = (printf("%s\n", data->pwd) * 0);
	else if (!ft_strcmp(wrd[0], "export"))
		exit_status = ft_export(wrd, &data->env);
	else if (!ft_strcmp(wrd[0], "unset"))
		exit_status = ft_unset(wrd, &data->env);
	else if (!ft_strcmp(wrd[0], "env") && !wrd[1])
		exit_status = ft_print_env(data->env);
	else if (!ft_strcmp(wrd[0], "exit"))
		exit_status = ft_exit(data, wrd);
	else
		exit_status = ft_executable(wrd, data);
	return (exit_status);
}
