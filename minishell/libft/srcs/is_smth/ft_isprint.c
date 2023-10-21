/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:18:13 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/10 11:01:10 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function checks if an integer is printable.
 * @param c 
	The integer to be checked.
 * @return 
	c if it really is printable, 0 if it is not.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
