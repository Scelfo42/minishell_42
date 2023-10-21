/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:18:43 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/08 15:28:25 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	ft_isalldigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

int	ft_exit(t_data *data, char **wrd)
{
	int	num;

	num = 0;
	ft_printf_fd(1, "exit\n");
	if (ft_matlen(wrd) <= 2)
	{
		if (ft_matlen(wrd) == 2 && ft_isalldigit(wrd[1]))
			num = ft_atoi(wrd[1]);
		else if (wrd[1])
			num = ft_print_exit_error(wrd[1]);
		data->lexer = ft_free_lexer(data);
		data->env_matrix = ft_free_matrix(data->env_matrix);
		ft_free_data(data);
		while (num > 255)
			num -= 256;
		while (num < 0)
			num += 256;
		exit(num);
	}
	else
	{
		ft_printf_fd(2, "racoonshell: exit: too many arguments\n");
		return (1);
	}
	return (0);
}
