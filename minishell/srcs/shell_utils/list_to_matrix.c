/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:17:06 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/04 14:31:40 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_list_to_matrix(t_list *list)
{
	char	**matrix;
	t_list	*tmp;
	int		i;
	int		count;
	char	*join_equal;

	tmp = list;
	matrix = NULL;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	matrix = ft_calloc(count + 1, sizeof(char *));
	i = -1;
	tmp = list;
	while (tmp)
	{
		join_equal = ft_strjoin(tmp->name, "=");
		matrix[++i] = ft_strjoin(join_equal, tmp->content);
		tmp = tmp->next;
		free(join_equal);
	}
	return (matrix);
}
