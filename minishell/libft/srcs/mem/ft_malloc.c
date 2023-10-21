/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:42:09 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/21 17:55:35 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This functions will just malloc a void pointer and will set all the memory
	inside it to 0. For reference, each byte will be: '\0'.
 * @param size
	The size of each space of memory. For example: sizeof(char) | sizeof(int)
	| ...
 * @return
	The malloc'ed pointer.
*/

void	*ft_malloc(size_t size)
{
	return (malloc(size));
}
