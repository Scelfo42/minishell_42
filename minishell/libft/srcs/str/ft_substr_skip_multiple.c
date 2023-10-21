/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_skip_multiple.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:50:06 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/08 13:25:30 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_skip_multiple(char *s, unsigned int start, size_t len, \
	char *skip)
{
	size_t		i;
	char		*str;
	size_t		s_len;
	size_t		shorter;

	i = 0;
	s_len = ft_strlen(s);
	shorter = ft_minmem(s_len, len, start);
	str = ft_calloc(shorter + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < shorter && start < s_len)
	{
		while (s[start + i] && ft_strchr(skip, s[start + i]))
		{
			start++;
			shorter--;
		}
		if (i > shorter)
			break ;
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
