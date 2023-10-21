/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:34:02 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/21 17:55:23 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This functions set all the memory inside a pointer to 0. For reference,
	each byte will be: '\0'.
 * @param ptr
	Supposedly a malloc'ed pointer or just a pointer.
 * @param n
	How many bytes you want to set to zero.
*/

void	ft_bzero(void *ptr, size_t n)
{
	ft_memset(ptr, 0, n);
}
