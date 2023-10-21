/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:24:28 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/04 14:24:55 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_find_end_quote(char *prompt, int *flag, char quote)
{
	int	i;
	int	update_flag;

	i = 0;
	update_flag = 1;
	while (prompt[++i] && prompt[i] != quote)
		continue ;
	if (prompt[i] == quote)
		update_flag++;
	*flag = update_flag;
	return (i);
}
