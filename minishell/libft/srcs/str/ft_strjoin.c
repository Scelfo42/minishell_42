/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:16:29 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/04 13:26:41 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function conatenates/joins a whole string at the end of another.
 * @param s1
	The first string.
 * @param s2
	The second string.
 * @return
	The new string that is the result of the concatenation between the 2.
*/

char	*ft_strjoin(char *s1, char *s2)
{
	int		c;
	int		k;
	char	*new;

	c = 0;
	k = 0;
	new = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	while (s1 && s1[c] != '\0')
	{
		new[c] = s1[c];
		c++;
	}
	while (s2 && s2[k] != '\0')
	{
		new[c + k] = s2[k];
		k++;
	}
	new[c + k] = '\0';
	return (new);
}
