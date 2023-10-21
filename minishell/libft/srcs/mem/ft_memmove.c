/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:49:41 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/10 15:36:28 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function move some memory from inside a pointer to another one.
 * @param dest
	The destination pointer.
 * @param src
	The source pointer.
 * @param n
	How many bytes have to be moved.
 * @return
	The pointer where the memory has been moved.
*/

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*dst;
	char	*source;

	if (!dest && !src)
		return (NULL);
	dst = (char *) dest;
	source = (char *) src;
	if (source <= dst)
	{
		while (n--)
			dst[n] = source[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
