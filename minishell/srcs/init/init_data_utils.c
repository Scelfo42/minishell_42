/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:17:51 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/04 14:17:52 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_add_back_env(t_list **head, t_list *new)
{
	t_list	*last;

	if (new)
	{
		if (*head)
		{
			last = ft_last_node_env(*head);
			last->next = new;
		}
		else
			*head = new;
	}
}

t_list	*ft_last_node_env(t_list *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}
