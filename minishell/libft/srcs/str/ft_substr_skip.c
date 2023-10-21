/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_skip.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:46:26 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/07 16:57:15 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_skip(char *s, unsigned int start, size_t len, char skip)
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
		while (s[start + i] == skip && shorter > 0)
		{
			start++;
			shorter--;
		}
		if (i >= shorter || shorter == 0)
			break ;
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
