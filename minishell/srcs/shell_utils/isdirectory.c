/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdirectory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:17:10 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/04 14:27:45 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isdirectory(char *dir_name)
{
	DIR	*dirp;

	dirp = opendir(dir_name);
	return (closedir(dirp));
}
