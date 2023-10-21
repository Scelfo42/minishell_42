/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:17:33 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/08 15:29:24 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_expand_wrd_red(t_data *data, char *which)
{
	t_lexer	*tmp;
	char	**wrd_red;
	int		i;

	tmp = data->lexer;
	while (tmp)
	{
		i = 0;
		if (!ft_strcmp(which, "wrd"))
			wrd_red = tmp->wrd;
		else
			wrd_red = tmp->red;
		while (wrd_red[i])
		{
			if (ft_expansion_needed(wrd_red[i]))
				wrd_red[i] = ft_expand_if_valid(wrd_red[i], data);
			wrd_red[i] = ft_skip_quotes(wrd_red[i]);
			i++;
		}
		tmp = tmp->next;
	}
}

char	*ft_skip(char *old_result, char *before_quotes)
{
	char	*new_result;

	new_result = ft_custom_realloc(ft_strjoin(old_result, before_quotes), \
		ft_strlen(old_result) + ft_strlen(before_quotes) + 1, sizeof(char));
	free(old_result);
	free(before_quotes);
	old_result = NULL;
	before_quotes = NULL;
	return (new_result);
}

char	*ft_modify_result(char *old_result, char *var)
{
	char	*new_result;

	new_result = ft_custom_realloc(ft_strjoin(old_result, var), \
		ft_strlen(old_result) + ft_strlen(var) + 1, sizeof(char));
	free(old_result);
	free(var);
	old_result = NULL;
	var = NULL;
	return (new_result);
}

char	*ft_insert_non_variable(char *old_result, char *original, int *i)
{
	char	*new_result;
	char	*until_var;
	int		i_move;

	i_move = ft_strlen_offset(original, '$');
	until_var = ft_substr(original, 0, i_move);
	new_result = ft_custom_realloc(ft_strjoin(old_result, until_var), \
		ft_strlen(old_result) + i_move + 1, sizeof(char));
	free(until_var);
	free(old_result);
	until_var = NULL;
	old_result = NULL;
	*i += i_move;
	return (new_result);
}
