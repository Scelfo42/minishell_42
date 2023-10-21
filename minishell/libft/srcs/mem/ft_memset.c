/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:27:15 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/10 15:38:20 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function fill of c all the space of memory of s.
 * @param s
	The pointer where blocks will be filled by c.
 * @param c
	The parameter to fill the pointer.
 * @param n
	How many bytes have to be filled.
 * @return
	The pointer with the memory filled.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	char	*cast_s;

	cast_s = (char *)s;
	while (n > 0)
	{
		cast_s[n - 1] = c;
		n--;
	}
	return (s);
}
