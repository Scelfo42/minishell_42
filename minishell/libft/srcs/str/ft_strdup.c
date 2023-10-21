/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:44:52 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/26 13:44:42 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function duplicates the content of a string into a new one.
 * @param s
	The string that has to be duplicated.
 * @return
	The duplicated string.
*/

char	*ft_strdup(char *s)
{
	char	*new_s;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s) + 1;
	new_s = ft_calloc(s_len, sizeof(char));
	if (!new_s)
		return (NULL);
	ft_memcpy(new_s, s, s_len);
	return (new_s);
}
