/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:48:13 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/10 16:51:12 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function writes the address of a pointer.
 * @param ptr
	The parameter to be printed.
 * @return
	The length of the printed pointer + 2 for 0x.
*/

int	ft_print_ptr(uintptr_t ptr)
{
	char	*hex_arr;
	char	arr[16];
	int		i;
	int		len;

	hex_arr = "0123456789abcdef";
	i = 15;
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	while (ptr > 0)
	{
		arr[i] = hex_arr[ptr % 16];
		ptr /= 16;
		i--;
	}
	write(1, "0x", 2);
	len = 16 - (++i);
	write(1, &arr[i], len);
	return (len + 2);
}
