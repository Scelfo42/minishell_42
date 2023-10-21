/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:18:27 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/08 13:26:54 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*ft_cancel_node_elements(t_list *node)
{
	free(node->content);
	free(node->name);
	node->flag_env = false;
	node->flag_export = false;
	free(node);
	node = NULL;
	return (node);
}

static t_list	*ft_remove_node(t_list *head, char *var_name)
{
	int		position;
	t_list	*tmp;
	t_list	*prev;

	prev = head;
	position = ft_varexist(head, var_name);
	if (position == INT_MAX)
		return (head);
	while (position-- > 1)
		prev = prev->next;
	tmp = prev->next;
	prev->next = tmp->next;
	tmp->next = NULL;
	tmp = ft_cancel_node_elements(tmp);
	return (head);
}

int	ft_unset(char **vars, t_list **env)
{
	char	*var_name;
	int		times;
	int		error_occured;

	var_name = NULL;
	times = ft_matlen(vars) - 1;
	error_occured = 0;
	while (times > 0)
	{
		var_name = ft_strdup(vars[times--]);
		if (ft_isidentifier(var_name, true) && \
			var_name[ft_strlen(var_name) - 1] != '=')
			*env = ft_remove_node(*env, var_name);
		else
			error_occured = 1;
		free(var_name);
		var_name = NULL;
	}
	return (error_occured);
}
