/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:58:16 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/21 17:51:21 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function creates and returns a new array, 
	possibly the same size as the one passed as parameter, 
	with the same content of the one mentioned before.
 * @param arr 
	The array to be copied
 * @param size
	The size that the new array will have. 
	(it is intended that the 2 arrays will have the same size)
 * @return 
	The array that has been copied.
*/

int	*ft_arrcpy(int *arr, int size)
{
	int	*new_arr;
	int	i;

	new_arr = ft_calloc(size, sizeof(int));
	i = -1;
	while (++i < size)
		new_arr[i] = arr[i];
	return (new_arr);
}
