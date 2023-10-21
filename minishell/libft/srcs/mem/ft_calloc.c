/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:42:50 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/21 17:56:04 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This functions will malloc a void pointer and will set all the memory
	inside it to 0. For reference, each byte will be: '\0'.
 * @param nmemb
	The number of bytes you want to allocate memory for.
 * @param size
	The size of each space of memory. For example: sizeof(char) | sizeof(int)
	| ...
 * @return
	The malloc'ed pointer.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*zero_mem;
	size_t	n_s;

	n_s = nmemb * size;
	if (!nmemb || !size)
		return (ft_strdup(""));
	if (n_s < nmemb)
		return (NULL);
	zero_mem = malloc(n_s);
	if (zero_mem == NULL)
		return (NULL);
	ft_bzero(zero_mem, n_s);
	return (zero_mem);
}
