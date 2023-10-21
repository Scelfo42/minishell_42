/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:06:30 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/21 17:50:05 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function takes a string that will be rewritten without, 
	at the start and at the end of it, the char found in set.
 * @param s1
	The starting string.
 * @param set
	The string where there is the char to be trimmed in s1.
 * @return
	The new string trimmed.
*/

char	*ft_strtrim(char *s1, char *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !set)
		return (ft_strdup(s1));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	if (start != end)
	{
		while (ft_strchr(set, s1[end]))
			end--;
		free(set);
		return (ft_substr(s1, start, (end - start + 1)));
	}
	free(set);
	return (ft_strdup(&s1[start]));
}
