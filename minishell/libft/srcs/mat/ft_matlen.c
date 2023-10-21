/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:17:19 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/10 11:19:07 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	Just like strlen, only that it doesn't count chars, it counts strings.
 * @param mat
	The matrix where the strings will be counted.
 * @return 
	The number of strings found.
*/

int	ft_matlen(char **mat)
{
	int	i;

	i = 0;
	while (mat[i] != 0)
		i++;
	return (i);
}
