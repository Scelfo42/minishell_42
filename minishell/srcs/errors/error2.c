/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:23:09 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/07 15:24:03 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_exit_error(char *str)
{
	ft_printf_fd(2, "racoonshell: exit: %s: numeric argument required\n", str);
	return (2);
}
