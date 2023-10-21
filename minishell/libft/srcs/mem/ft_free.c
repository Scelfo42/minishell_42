/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:17:48 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/21 17:55:18 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This functions will free the memory of the pointer passed as parameter,
	which is pointing to the original variable.
 * @return
	The free'ed pointer.
*/

void	*ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
	return (*ptr);
}

void	ft_free_stack(t_stack **stack)
{
	if ((*stack)->size > 1)
	{
		while ((*stack)->top->next)
		{
			(*stack)->top = (*stack)->top->next;
			free((*stack)->top->prev);
		}
	}
	if ((*stack)->size != 0)
		free((*stack)->top);
	free(*stack);
}

char	**ft_free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix && matrix[++i])
		ft_free((void **)&matrix[i]);
	free(matrix);
	matrix = NULL;
	return (matrix);
}
