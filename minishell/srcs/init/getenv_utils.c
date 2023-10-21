/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:11:06 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/04 14:11:07 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_getvaluelen(char *s)
{
	int	i;
	int	quote;
	int	equal;

	i = 0;
	quote = 0;
	equal = 0;
	while (s[i])
	{
		if (s[i] == 34 || s[i] == 39)
			quote++;
		else if (s[i] == '=' && !equal)
			equal++;
		i++;
	}
	return (quote + equal);
}

char	*ft_getvarname(char *s, int name_len)
{
	char	*name;
	int		i;

	i = 0;
	name = ft_calloc(1, sizeof(char) * name_len + 1);
	while (s[i] && s[i] != '=')
	{
		name[i] = s[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

char	*ft_getvarcontent(char *s, int content_len)
{
	char	*content;
	int		i;
	int		j;

	content = ft_calloc(1, sizeof(char) * content_len + 1);
	i = 0;
	j = 0;
	while (s[i] && s[i] != '=')
		i++;
	if (s[i] == '=')
		i++;
	if (s[i] == 34 || s[i] == 39)
		i++;
	while (s[i] && s[i] != 34 && s[i] != 39)
	{
		content[j] = s[i];
		j++;
		i++;
	}
	content[content_len] = '\0';
	return (content);
}
