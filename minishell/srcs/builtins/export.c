/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:18:38 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/08 15:49:32 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	ft_isidentifier(char *str, bool msg)
{
	if (!ft_isalpha(str[0]) && str[0] != '_')
	{
		if (msg)
		{
			ft_printf_fd(2, "racoonshell: export: `%s': ", str);
			ft_printf_fd(2, "not a valid identifier\n", str);
		}
		return (false);
	}
	return (true);
}

static void	ft_set_void_variable(t_list **env, char *var)
{
	t_list	*tmp;

	tmp = *env;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_init_nodino(ft_strdup(var), false, true);
}

static void	ft_export_variable2(t_list **env, char *vars)
{
	t_list	*tmp;
	int		position;

	tmp = *env;
	position = ft_varexist(*env, vars);
	while (position-- > 0)
		tmp = tmp->next;
	tmp->flag_env = true;
	tmp->flag_export = true;
}

static int	ft_export_variable(t_list **env, char **vars)
{
	int		i;
	int		error_occured;

	i = 0;
	error_occured = 0;
	while (vars[++i])
	{
		if (!ft_isidentifier(vars[i], true))
			error_occured = 1;
		else if (ft_isvariable(vars[i]))
			ft_setvariable(env, vars[i], true, true);
		else if (ft_varexist(*env, vars[i]) && \
			ft_varexist(*env, vars[i]) != INT_MAX && \
			ft_strlen_offset(vars[i], '=') != '\0')
			ft_export_variable2(env, vars[i]);
		else
			ft_set_void_variable(env, vars[i]);
	}
	return (error_occured);
}

int	ft_export(char **vars, t_list **env)
{
	int		error_occured;

	error_occured = 0;
	if (!vars[1])
		ft_print_export(*env);
	else
		error_occured = ft_export_variable(env, vars);
	return (error_occured);
}
