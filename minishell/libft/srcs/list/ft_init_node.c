/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:29:08 by chri42            #+#    #+#             */
/*   Updated: 2023/08/21 17:53:16 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function insert a new_node after the last node of the stack.
	If the stack is empty, it will become the top and bottom of it.
 * @param data
	The integer to be inserted in the new_node->data variable.
 * @return 
	The new node that will have the data inserted and
	it is not connected with any node.
*/

t_node	*ft_init_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
