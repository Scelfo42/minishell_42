/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:11:46 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/04 14:42:21 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_init_nodino(char *var, bool flag_env, bool flag_export)
{
	t_list	*new;
	int		full_len;
	int		name_len;
	int		value_len;

	new = ft_calloc(1, sizeof(t_list));
	full_len = ft_strlen(var);
	name_len = ft_strlen_offset(var, '=');
	value_len = ft_getvaluelen(var);
	new->name = ft_getvarname(var, name_len);
	new->content = ft_getvarcontent(var, (full_len - name_len - value_len));
	new->flag_env = flag_env;
	new->flag_export = flag_export;
	new->next = NULL;
	free(var);
	return (new);
}

t_list	*ft_get_env(char **envp)
{
	int		i;
	t_list	*env;
	t_list	*new_node;

	i = -1;
	env = NULL;
	while (envp[++i])
	{
		new_node = ft_init_nodino(ft_strdup(envp[i]), true, true);
		ft_add_back_env(&env, new_node);
	}
	return (env);
}

t_lexer	*ft_init_lexer(void)
{
	t_lexer	*lexer;

	lexer = ft_calloc(1, sizeof(t_lexer));
	lexer->wrd = NULL;
	lexer->red = NULL;
	lexer->next = NULL;
	return (lexer);
}

t_data	*ft_init_data(char **envp)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data->env = ft_get_env(envp);
	data->prompt = 0;
	data->pwd = getcwd(NULL, 0);
	data = ft_init_history(data);
	data->exit_status = 0;
	data->infile_fd = -2;
	data->outfile_fd = -2;
	data->stdin_copy = dup(0);
	data->stdout_copy = dup(1);
	data->env_matrix = NULL;
	return (data);
}
