/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:17:39 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/04 14:17:40 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_free_list(t_list *node)
{
	t_list	*tmp;

	tmp = NULL;
	while (node)
	{
		tmp = node->next;
		free(node->name);
		free(node->content);
		node->flag_export = false;
		node->flag_env = false;
		node->next = NULL;
		free(node);
		node = tmp;
	}
	return (node);
}

t_lexer	*ft_free_lexer(t_data *data)
{
	t_lexer	*tmp;

	tmp = NULL;
	while (data->lexer)
	{
		tmp = data->lexer->next;
		data->lexer->wrd = ft_free_matrix(data->lexer->wrd);
		data->lexer->red = ft_free_matrix(data->lexer->red);
		data->lexer->next = NULL;
		free(data->lexer);
		data->lexer = tmp;
	}
	return (data->lexer);
}

int	ft_free_data(t_data *data)
{
	int	exit_status;

	exit_status = data->exit_status;
	data->env = ft_free_list(data->env);
	close(data->history_fd);
	free(data->history);
	free(data->pwd);
	free(data);
	return (exit_status);
}
