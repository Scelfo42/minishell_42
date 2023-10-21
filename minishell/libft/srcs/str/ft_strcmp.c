/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:36:47 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/21 17:45:56 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function compares 2 strings. 
 * @param s1
	The first string.
 * @param s2
	The second string.
 * @return
	if the 2 strings are exactly the same, 0 will be returned, 
	otherwise the difference between the first occurence of inequality found.
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s1[++i])
	{
		if (s1[i] != s2[i])
			break ;
	}
	return (s1[i] - s2[i]);
}
