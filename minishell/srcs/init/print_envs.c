/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_envs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:17:44 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/04 14:17:45 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_print_env(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->flag_env == true)
			printf("%s=%s\n", tmp->name, tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_print_export(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->flag_export == true && tmp->flag_env == true)
			printf("declare -x %s=\"%s\"\n", tmp->name, tmp->content);
		else if (tmp->flag_export == true && tmp->flag_env == false)
			printf("declare -x %s\n", tmp->name);
		tmp = tmp->next;
	}
	return (0);
}
