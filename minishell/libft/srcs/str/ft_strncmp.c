/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:24:28 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/21 17:47:08 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function compares 2 strings for a certain amount of bytes. 
 * @param s1
	The first string.
 * @param s2
	The second string.
 * @param n
	The number of bytes for that the 2 strings will be compared.
 * @return
	if the 2 strings are exactly the same, 0 will be returned, 
	otherwise the difference between the first occurence of inequality found.
*/

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			c;

	s_1 = (unsigned char *) s1;
	s_2 = (unsigned char *) s2;
	c = 0;
	if (n == 0)
		return (0);
	while ((c < n && s_1[c] != '\0') || (s_2[c] != '\0'))
	{
		if (s_1[c] != s_2[c])
			return (s_1[c] - s_2[c]);
		c++;
		if (c == n)
			return (0);
	}
	return (0);
}
