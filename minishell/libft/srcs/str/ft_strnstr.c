/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:12:41 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/21 17:42:19 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function locates the first occurrence of the null-terminated 
	string little in the string big, 
	where not more than len characters are searched.
	Characters that appear after a ‘\0’ character are not searched. 
 * @param big
	The largest string.
 * @param little
	The smallest string.
 * @param len
	The number of bytes for that the big string will be iterated.
 * @return
	If little is an empty string, big is returned; 
	if little occurs nowhere in big, NULL is returned;
	otherwise a pointer to the first character of the first occurrence 
	of little is returned.
*/

char	*ft_strnstr(char *big, char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	c1;
	size_t	c2;

	b = (char *)big;
	l = (char *)little;
	c1 = 0;
	if (l[c1] == '\0')
		return (b);
	while (b[c1] != '\0')
	{
		c2 = 0;
		while (b[c1 + c2] == l[c2] && c1 + c2 < len)
		{
			if (b[c1 + c2] == '\0' || l[c2++] == '\0')
				break ;
		}
		if (l[c2++] == '\0')
			return (&b[c1]);
		c1++;
	}
	return (0);
}
