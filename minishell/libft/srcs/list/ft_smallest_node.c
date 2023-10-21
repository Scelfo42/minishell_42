/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallest_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:28:40 by chri42            #+#    #+#             */
/*   Updated: 2023/08/21 17:52:55 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function iterates the stack starting from the top 
	all the way to the bottom, searching for the smallest data inside the stack.
 * @param top
	The pointer to the top of the stack.
 * @return 
	The smallest data found.
*/

int	ft_smallest(t_node *top)
{
	int		smallest;
	t_node	*tmp;

	smallest = 0;
	tmp = top;
	while (top)
	{
		top = top->next;
		while (top && tmp->data < top->data)
			top = top->next;
		smallest = tmp->data;
		tmp = top;
	}
	return (smallest);
}
