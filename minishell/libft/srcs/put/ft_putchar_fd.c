/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:53:20 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/12 13:48:24 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function writes a char in a specific fd.
 * @param c
	The char to be printed.
 * @param fd
	The fd where it should be printed.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
