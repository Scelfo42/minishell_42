/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:39:18 by cscelfo           #+#    #+#             */
/*   Updated: 2023/06/12 14:55:51 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function converts a string (made of ASCII characters) into a float. 
 * @param str
	The string which contains, hypothetically, the number to be converted.
 * @return
	The number represented in float.
*/

double	ft_atof(char *str)
{
	int		i;
	double	res;
	int		sign;
	double	dec;

	i = 0;
	sign = 1;
	res = 0.0;
	dec = 1.0;
	if (str[i] == '-')
		sign = -1;
	i += (str[i] == '-' || str[i] == '+');
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		dec *= 10;
	}
	return (res / dec * sign);
}
