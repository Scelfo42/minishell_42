/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_biggest_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 21:29:14 by chri42            #+#    #+#             */
/*   Updated: 2023/08/21 17:52:43 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function iterates the stack starting from the top all the way
	to the bottom, searching for the biggest data inside the stack.
 * @param top
	The pointer to the top of the stack.
 * @return 
	The biggest data found.
*/

int	ft_biggest(t_node *top)
{
	int		biggest;
	t_node	*tmp;

	biggest = 0;
	tmp = top;
	while (top)
	{
		top = top->next;
		while (top && tmp->data > top->data)
			top = top->next;
		biggest = tmp->data;
		tmp = top;
	}
	return (biggest);
}
