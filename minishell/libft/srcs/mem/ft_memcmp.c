/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 23:42:55 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/10 15:34:37 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function check for diff between 2 pointers.
 * @param s1
	The first pointer.
 * @param s2
	The second pointer.
 * @param n
	For how many bytes the pointers have to be iterated.
 * @return
	The diff between the 2 pointers.
*/

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			c;

	s_1 = (unsigned char *) s1;
	s_2 = (unsigned char *) s2;
	c = 0;
	if (c == n)
		return (0);
	while (c < n)
	{
		if (s_1[c] != s_2[c])
			return (s_1[c] - s_2[c]);
		c++;
	}
	return (0);
}
