/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:11:44 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/10 10:59:50 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function checks if an integer is part of the ASCII table.
 * @param c 
	The integer to be checked.
 * @return 
	c if it really is part of the ASCII, 0 if it is not.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
