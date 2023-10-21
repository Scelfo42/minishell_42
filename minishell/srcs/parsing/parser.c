/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:30:33 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/08 16:00:40 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ft_pipe_void(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (!str[i] || str[i] == '|')
		return (false);
	while (str[i])
	{
		i += ft_strlen_offset(&str[i], '|');
		if (!str[i])
			break ;
		else if (!str[++i])
			return (false);
		while (str[i] && (ft_isspace(str[i])))
			i++;
		if (!str[i] || str[i] == '|')
			return (false);
	}
	return (true);
}

static int	ft_check_quotes(char *prompt)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (prompt[i])
	{
		if (prompt[i] == 34)
			i += ft_find_end_quote(&prompt[i], &flag, 34);
		else if (prompt[i] == 39)
			i += ft_find_end_quote(&prompt[i], &flag, 39);
		if (prompt[i])
			i++;
	}
	return (flag);
}

static int	ft_check_red(char **red)
{
	int	i;
	int	j;

	i = -1;
	while (red[++i])
	{
		if (red[i] && red[i][0] == '>' && red[i][1] == '>' && \
			(red[i][2] == '>' || red[i][2] == '<'))
			return (2);
		else if (red[i] && red[i][0] == '<' && red[i][1] == '<' && \
			(red[i][2] == '>' || red[i][2] == '<'))
			return (2);
		else if (red[i] && red[i][0] == '>' && red[i][1] == '<')
			return (2);
		else if (red[i] && red[i][0] == '<' && red[i][1] == '>')
			return (2);
		j = ft_decide_len(red[i], "<>");
		if (red[i][j + 1] == '>' || red[i][j + 1] == '<')
			j++;
		while (red[i][++j] && ft_isspace(red[i][j]))
			continue ;
		if (!red[i][j] || red[i][j] == '>' || red[i][j] == '<')
			return (2);
	}
	return (0);
}

static int	ft_check_delimiter(char **red)
{
	int	i;
	int	j;

	i = 0;
	while (red[i])
	{
		j = 2;
		if (red[i] && !ft_strncmp(red[i], "<<", 2))
		{
			while (red[i][j] && ft_isspace(red[i][j]))
				j++;
			if (!red[i][j])
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_parser(t_data *data)
{
	int	exit_status;

	exit_status = 0;
	if (ft_check_quotes(data->prompt) % 2 != 0)
		exit_status = ft_error_quotes();
	else if (!ft_pipe_void(data->prompt))
		exit_status = ft_pipe_syntax_error('|');
	else if (ft_lexer(data))
		exit_status = 1;
	else if (ft_check_red(data->lexer->red) || \
		ft_check_delimiter(data->lexer->red))
		exit_status = ft_red_syntax_error("> or <");
	if (!exit_status)
	{
		ft_expand_wrd_red(data, "wrd");
		ft_expand_wrd_red(data, "red");
	}
	return (exit_status);
}
