/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:31:01 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/21 17:55:47 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function search for the same memory address as c inside the memory
	pointed to by s.
 * @param s
	The pointer to be iterated.
 * @param c
	The parameter to be found.
 * @param n
	How many bytes have to be iterated inside s.
 * @return
	A pointer starting from the point where c was found, if it wasn't it will
	return NULL.
*/

void	*ft_memchr(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cast_s;

	i = 0;
	cast_s = (unsigned char *)s;
	while (i < n)
	{
		if (cast_s[i] == (unsigned char)c)
			return (&cast_s[i]);
		i++;
	}
	return (NULL);
}
