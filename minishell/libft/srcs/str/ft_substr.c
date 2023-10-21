/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:49:13 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/23 15:22:41 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function takes a string that will be rewritten from a starting 
	point to a certain number of bytes, creating like so a substring.
 * @param s
	The starting string.
 * @param start
	The index from where the string will start to be iterated.
 * @param len
	The number of bytes that the substring will be in length.
 * @return
	The substring created.
*/

size_t	ft_minmem(size_t s_len, size_t len, unsigned int start)
{
	if (len < s_len)
		return (len);
	else
	{
		if (start > s_len)
			return (0);
		return (s_len);
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
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
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
