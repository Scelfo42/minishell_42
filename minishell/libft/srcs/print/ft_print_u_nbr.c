/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:25:11 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/12 13:47:15 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function writes an unsigned number.
 * @param n
	The number to be printed.
 * @return
	The length of the printed number.
*/

size_t	ft_put_u_nbr(long int n)
{
	char	arr[11];
	int		len;
	int		i;

	i = 10;
	len = 0;
	while (n >= 10)
	{
		arr[i--] = (n % 10) + 48;
		n /= 10;
	}
	if (n < 10)
		arr[i] = n + 48;
	len = 11 - i;
	write(1, &arr[i], len);
	return (len);
}
