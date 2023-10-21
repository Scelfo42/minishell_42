/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:47:25 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/23 18:23:57 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function concatenates the content of a string at the end of another.
 * @param dst
	The destination string.
 * @param src
	The source string.
 * @param size
	The number of bytes that will be concatenated.
 * @return
	The total number of bytes in the concatenated string.
*/

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	c;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	c = 0;
	if (d >= size)
		return (size + s);
	while (src[c] && c < size - d - 1)
	{
		dst[d + c] = src[c];
		c++;
	}
	dst[d + c] = '\0';
	return (d + s);
}
