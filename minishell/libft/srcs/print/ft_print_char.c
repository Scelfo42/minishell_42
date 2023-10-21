/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:09:23 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/10 15:39:24 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function writes a char.
 * @param c
	The parameter to be written.
 * @return
	Just 1.
*/

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
