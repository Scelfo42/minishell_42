/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:17:44 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/12 13:59:21 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function search for a specific char inside a string.
 * @param s
	The string to be iterated.
 * @param c
	The char that you would want to find.
 * @return
	A pointer to the last occurence of c in s.
*/

char	*ft_strrchr(char *s, int c)
{
	int	end_to_st;

	end_to_st = ft_strlen(s);
	if (c == 0)
		return ((char *)&s[end_to_st]);
	c %= 256;
	while (end_to_st >= 0)
	{
		if (s[end_to_st] == c)
			return ((char *)&s[end_to_st]);
		end_to_st--;
	}
	return (NULL);
}
