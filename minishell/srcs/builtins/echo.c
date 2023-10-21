/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:23:46 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/05 19:12:14 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **wrd)
{
	int		i;
	int		j;
	bool	flag;

	i = 0;
	flag = false;
	if (wrd[0] && !ft_strncmp(wrd[0], "-n\0", 3))
		flag = ++i;
	while (wrd[i])
	{
		j = 0;
		while (wrd[i][j])
		{
			write(STDOUT_FILENO, &wrd[i][j], 1);
			j++;
		}
		i++;
		if (wrd[i])
			write(STDOUT_FILENO, " ", 1);
	}
	if (!flag)
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
