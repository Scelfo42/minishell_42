/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node_before.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:30:10 by chri42            #+#    #+#             */
/*   Updated: 2023/08/21 17:52:31 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function insert a new_node before the first node of the stack.
	If the stack is empty, it will become the top and bottom of it.
 * @param first_node
	The first node of the stack.
 * @param to
	The stack to where the node will be inserted.
 * @return 
	It just works with original pointers so nothing will be returned.
*/

void	ft_add_before(t_node *first_node, t_stack **to)
{
	if (first_node)
	{
		if ((*to)->top)
		{
			(*to)->top->prev = first_node;
			first_node->next = (*to)->top;
			(*to)->top = (*to)->top->prev;
		}
		else
		{
			(*to)->top = first_node;
			(*to)->bottom = (*to)->top;
		}
	}
}
