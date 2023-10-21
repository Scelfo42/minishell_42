/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:10:19 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/04 14:10:20 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_getenv_content(t_list *env, char *name)
{
	t_list	*tmp;

	tmp = env;
	while (tmp && ft_strcmp(tmp->name, name))
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	return (tmp->content);
}

static int	ft_change_dir(char *path, t_data *data)
{
	char	pwd[1000];

	if (chdir(path) == -1)
	{
		ft_printf_fd(2, "racoonshell: cd: %s: ", path);
		ft_printf_fd(2, "no such file or directory\n", path);
		return (1);
	}
	getcwd(pwd, 1000);
	free(data->pwd);
	data->pwd = NULL;
	data->pwd = ft_strdup(pwd);
	return (0);
}

int	ft_cd(t_data *data)
{
	int		len;
	char	*path;
	char	*home;

	len = ft_matlen(data->lexer->wrd);
	home = ft_getenv_content(data->env, "HOME");
	path = NULL;
	if ((!home && len == 1) || len > 2)
		return (ft_cd_error(len, home));
	else if (len == 1)
		path = home;
	else
		path = data->lexer->wrd[1];
	if (ft_change_dir(path, data))
		return (1);
	return (0);
}
