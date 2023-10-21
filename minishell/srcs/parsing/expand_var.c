/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:17:27 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/08 15:33:33 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_expand_variable(char *str, t_data *data)
{
	int		i;
	char	*name;
	t_list	*tmp;

	i = 0;
	if (str[i] == '?')
		return (ft_itoa(data->exit_status));
	while (ft_isalnum(str[i]))
		i++;
	name = ft_substr(str, 0, i);
	tmp = data->env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
		{
			free(name);
			name = 0;
			return (ft_strdup(tmp->content));
		}
		tmp = tmp->next;
	}
	free(name);
	name = 0;
	return (NULL);
}

bool	ft_expansion_needed(char *str)
{
	int		i;

	i = ft_strlen_offset(str, '$');
	if (!str[i])
		return (false);
	return (true);
}

bool	ft_expansion_check(char *prompt, int breakpoint)
{
	int		i;
	char	quote;

	i = 0;
	while (prompt[i] && i < breakpoint)
	{
		if (prompt[i] == 34 || prompt[i] == 39)
		{
			quote = prompt[i];
			i += ft_jump_queck(&prompt[i], quote);
			if (i > breakpoint && quote == 39)
				return (false);
		}
		else
			i++;
	}
	return (true);
}

char	*ft_expand_if_valid(char *original, t_data *data)
{
	char	*result;
	int		i;

	i = 0;
	result = NULL;
	while (original[i])
	{
		result = ft_insert_non_variable(result, &original[i], &i);
		if (!original[i])
			break ;
		if (original[++i] && ft_expansion_check(original, i))
			result = ft_modify_result(result, \
				ft_expand_variable(&original[i], data));
		else
			result = ft_modify_result(result, ft_substr(&original[i - 1], \
				0, ft_decide_len(&original[i], "$\'\" ") + 1));
		while (ft_isalnum(original[i]))
			i++;
	}
	free(original);
	original = NULL;
	return (result);
}

char	*ft_skip_quotes(char *orig)
{
	char	*res;
	int		i;
	int		start;
	char	quote;

	if (orig[ft_strlen_offset(orig, 34)] == '\0' && \
		orig[ft_strlen_offset(orig, 39)] == '\0')
		return (orig);
	i = 0;
	res = NULL;
	while (orig[i])
	{
		start = i;
		while (orig[i] && orig[i] != 34 && orig[i] != 39)
			i++;
		if (orig[i] == 34 || orig[i] == 39)
		{
			quote = orig[i];
			i += ft_jump_queck(&orig[i], quote);
		}
		res = ft_skip(res, ft_substr_skip(&orig[start], 0, i - start, quote));
		if (!orig[i])
			break ;
	}
	return (ft_return_free(res, orig));
}
