/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setvariable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:18:33 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/07 16:24:47 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_offset(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_varexist(t_list *env, char *var_name)
{
	int		check;
	t_list	*tmp;
	char	*name;

	check = 0;
	tmp = env;
	name = ft_getvarname(var_name, ft_strlen_offset(var_name, '='));
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			free(name);
			return (check);
		}
		check++;
		tmp = tmp->next;
	}
	free(name);
	return (INT_MAX);
}

int	ft_setvariable(t_list **env, char *var, bool flag_env, bool flag_export)
{
	t_list	*tmp;
	int		check;
	int		length_diff;

	tmp = *env;
	check = ft_varexist(*env, var);
	length_diff = 0;
	if (check == INT_MAX)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_init_nodino(ft_strdup(var), flag_env, flag_export);
	}
	else
	{
		while (check-- > 0)
			tmp = tmp->next;
		free(tmp->content);
		length_diff = ft_strlen(var) - ft_strlen_offset(var, '=') - 1;
		tmp->content = ft_getvarcontent(var, length_diff);
	}
	return (0);
}

bool	ft_isvariable(char *str)
{
	int	i;

	i = 0;
	if (!ft_isalpha(str[i]) && str[i] != '_')
	{
		ft_printf_fd(2, "racoonshell: %s: command not found\n", str);
		return (false);
	}
	while (str && str[i])
	{
		if ((ft_isalnum(str[i]) || str[i] == '_') && str[i] != '=')
			i++;
		else
			break ;
	}
	if (str[i] == '=')
		return (true);
	return (false);
}
