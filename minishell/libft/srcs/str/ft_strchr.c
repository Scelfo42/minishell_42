/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:44:20 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/12 13:53:40 by cscelfo          ###   ########.fr       */
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
	A pointer to the first occurence of c in s.
*/

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s);
		i++;
	}
	if (s[i] == c)
		return (s);
	return (NULL);
}
