/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_after.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:30:06 by chri42            #+#    #+#             */
/*   Updated: 2023/08/21 17:52:21 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function insert a new_node after the last node of the stack.
	If the stack is empty, it will become the top and bottom of it.
 * @param a
	The pointer to the original stack.
 * @param new_node
	The new_node to be inserted in the stack.
 * @return 
	It just works with original pointers so nothing will be returned.
*/

void	ft_add_after(t_stack **a, t_node *new_node)
{
	if (new_node)
	{
		if ((*a)->top)
		{
			(*a)->bottom->next = new_node;
			new_node->prev = (*a)->bottom;
			(*a)->bottom = new_node;
		}
		else
		{
			(*a)->top = new_node;
			(*a)->bottom = (*a)->top;
		}
	}
}
