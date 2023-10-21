/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:30:24 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/04 14:12:07 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*ft_add_front_lexer(t_lexer **head)
{
	t_lexer	*tmp;

	tmp = ft_init_lexer();
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}

int	ft_fill_nodes(char *prompt, t_lexer *tmp)
{
	int	i;
	int	r;
	int	w;

	i = 0;
	r = 0;
	w = 0;
	while (prompt[i] && prompt[i] != '|')
	{
		if (ft_isspace(prompt[i]))
			i++;
		else if (prompt[i] == '>' || prompt[i] == '<')
		{
			tmp->red[r] = ft_clean_red(&prompt[i]);
			i += ft_red_len(&prompt[i]);
			r++;
		}
		else if (prompt[i] && prompt[i] != '|')
		{
			tmp->wrd[w] = ft_fill_wrd(&prompt[i]);
			i += ft_wrd_len(&prompt[i]);
			w++;
		}
	}
	return (i);
}

int	ft_red_count(char *prompt)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (prompt[i] && prompt[i] != '|')
	{
		while (ft_isspace(prompt[i]))
			i++;
		if (prompt[i] == '>' || prompt[i] == '<')
		{
			count++;
			i += ft_red_len(&prompt[i]);
		}
		else if (prompt[i] != '|')
			i += ft_wrd_len(&prompt[i]);
	}
	return (count);
}

int	ft_wrd_count(char *prompt)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (prompt[i] && prompt[i] != '|')
	{
		while (ft_isspace(prompt[i]))
			i++;
		if (prompt[i] && (prompt[i] == 34 || prompt[i] == 39))
		{
			count++;
			i += ft_jump_queck(&prompt[i], prompt[i]);
		}
		else if (prompt[i] == '>' || prompt[i] == '<')
			i += ft_red_len(&prompt[i]);
		else if (prompt[i] != '|')
		{
			count++;
			i += ft_wrd_len(&prompt[i]);
		}
		else
			i++;
	}
	return (count);
}

int	ft_lexer(t_data *data)
{
	t_lexer	*tmp;
	int		i;

	tmp = data->lexer;
	i = 0;
	while (data->prompt[i] && data->prompt[i] != '|')
	{
		tmp->wrd = ft_calloc(ft_wrd_count(&data->prompt[i]) + 1, \
			sizeof(char *));
		tmp->red = ft_calloc(ft_red_count(&data->prompt[i]) + 1, \
			sizeof(char *));
		tmp->wrd[ft_wrd_count(&data->prompt[i])] = NULL;
		tmp->red[ft_red_count(&data->prompt[i])] = NULL;
		i += ft_fill_nodes(&data->prompt[i], tmp);
		if (data->prompt[i] == '|')
		{
			if (data->prompt[i + 1] == '|')
				return (ft_pipe_syntax_error(data->prompt[i + 1]));
			tmp = ft_add_front_lexer(&data->lexer);
			i++;
		}
	}
	return (0);
}
