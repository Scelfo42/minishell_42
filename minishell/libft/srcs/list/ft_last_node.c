/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:28:59 by chri42            #+#    #+#             */
/*   Updated: 2023/06/10 11:15:02 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function iterates the stack until it reaches the last node of the stack.
 * @param top
	The pointer to the top of the stack.
 * @return 
	The last node of the stack.
*/

t_node	*ft_last_node(t_node *top)
{
	if (top && top->next)
	{
		while (top->next)
			top = top->next;
	}
	return (top);
}
