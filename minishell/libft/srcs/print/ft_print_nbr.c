/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:00:33 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/10 15:41:41 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function writes a number.
 * @param n
	The parameter to be written.
 * @return
	The length of the printed nbr.
*/

int	ft_putnbr(int n)
{
	char			arr[11];
	int				i;
	int				len;
	unsigned int	cn;

	i = 10;
	len = 0;
	cn = n;
	if (n < 0)
	{
		len = 1;
		cn = -n;
	}
	while (cn >= 10)
	{
		arr[i--] = (cn % 10) + 48;
		cn /= 10;
	}
	if (cn < 10)
		arr[i] = cn + 48;
	if (len == 1)
		arr[--i] = '-';
	len = 11 - i;
	write(1, &arr[i], len);
	return (len);
}
