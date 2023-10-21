/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:27:54 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/08 13:30:31 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_jump_queck(char *prompt, char quote)
{
	int	i;

	i = 0;
	while (prompt[++i] && prompt[i] != quote)
		continue ;
	if (prompt[i] == quote)
		i++;
	return (i);
}

int	ft_red_len(char *prompt)
{
	int	i;

	i = 0;
	while (prompt[i] && (prompt[i] == '>' || prompt[i] == '<') && \
		prompt[i] != '|')
		i++;
	while (prompt[i] && ft_isspace(prompt[i]) && prompt[i] != '|')
		i++;
	if (prompt[i] && (prompt[i] == 34 || prompt[i] == 39))
		i += ft_jump_queck(&prompt[i], prompt[i]);
	while (prompt[i] && !ft_isspace(prompt[i]) && prompt[i] != '|')
		i++;
	return (i);
}

int	ft_wrd_len(char *prompt)
{
	int	i;

	i = 0;
	if (prompt[i] && (prompt[i] == 34 || prompt[i] == 39))
	{
		i += ft_jump_queck(&prompt[i], prompt[i]);
		while (prompt[i] && prompt[i] != '>' && prompt[i] != '<' && \
			prompt[i] != '|' && !ft_isspace(prompt[i]))
			i++;
	}
	else
	{
		while (prompt[i] && prompt[i] != '>' && prompt[i] != '<' && \
			prompt[i] != '|' && !ft_isspace(prompt[i]))
		{
			if ((prompt[i + 1] == 34 || prompt[i + 1] == 39) && \
				prompt[i] == '=')
				i += ft_jump_queck(&prompt[i + 1], prompt[i + 1]);
			i++;
		}
	}
	return (i);
}

char	*ft_clean_red(char *prompt)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (prompt[i] == '>' || prompt[i] == '<')
		i++;
	j = i;
	while (ft_isspace(prompt[i]))
		i++;
	tmp = ft_calloc(1, (ft_red_len(prompt) - i + j) + 1);
	i = -1;
	while (prompt[++i] == '>' || prompt[i] == '<')
		tmp[i] = prompt[i];
	j = i;
	while (ft_isspace(prompt[i]))
		i++;
	while (prompt[i] && !ft_isspace(prompt[i]) && prompt[i] != '|')
		tmp[j++] = prompt[i++];
	return (tmp);
}

char	*ft_fill_wrd(char *prompt)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = ft_wrd_len(prompt);
	tmp = ft_calloc(1, j + 1);
	while (i < j)
	{
		tmp[i] = prompt[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
