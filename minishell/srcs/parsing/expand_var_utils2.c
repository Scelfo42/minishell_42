/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:36:07 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/08 15:34:26 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_return_free(char *to_ret, char *to_free)
{
	free(to_free);
	to_free = NULL;
	return (to_ret);
}

static int	ft_red_decide_len(char *prompt)
{
	int	input_red;
	int	output_red;

	input_red = ft_strlen_offset(prompt, '<');
	output_red = ft_strlen_offset(prompt, '>');
	if (input_red < output_red)
		return (input_red);
	return (output_red);
}

int	ft_decide_len(char *prompt, char *chars_to_decide)
{
	int	space;
	int	dollar;
	int	s_quote;
	int	d_quote;

	if (chars_to_decide[0] == '<' && chars_to_decide[1] == '>')
		return (ft_red_decide_len(prompt));
	dollar = ft_strlen_offset(prompt, '$');
	if (ft_strlen(chars_to_decide) > 1)
	{
		s_quote = ft_strlen_offset(prompt, 39);
		d_quote = ft_strlen_offset(prompt, 34);
		if (ft_strlen(chars_to_decide) > 3)
		{
			space = ft_strlen_offset(prompt, ' ');
			if (space < dollar && space < s_quote && space < d_quote)
				return (space);
		}
		if (s_quote < dollar && s_quote < d_quote)
			return (s_quote);
		else if (d_quote < dollar && d_quote < s_quote)
			return (d_quote);
	}
	return (dollar);
}
