/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:24:58 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/04 11:25:52 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_red_syntax_error(char *s)
{
	ft_printf_fd(2, "racoonshell: syntax error: ");
	ft_printf_fd(2, "unexpeted token '%s' near redirect\n", s);
	return (2);
}

int	ft_pipe_syntax_error(char c)
{
	ft_printf_fd(2, "racoonshell: syntax error: ");
	ft_printf_fd(2, "unexpeted token '%c' near pipe\n", c);
	return (2);
}

void	ft_ac_error(void)
{
	ft_printf_fd(2, "Passa ancora piu' di un argomento ");
	ft_printf_fd(2, "e la revy ti spezza le ossicine 💀\n");
	exit(1);
}

int	ft_cd_error(int len, char *home)
{
	if (len > 2)
		ft_printf_fd(2, "racoonshell: cd: too many arguments\n");
	else if (!home)
		ft_printf_fd(2, "racoonshell: cd: HOME not set\n");
	else
		ft_printf_fd(2, "racoonshell: cd: you found the impossible\n");
	return (1);
}

int	ft_error_quotes(void)
{
	ft_printf_fd(2, "racoonshell: syntax error: quote opened but not closed\n");
	return (2);
}
