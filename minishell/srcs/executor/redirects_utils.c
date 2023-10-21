/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:18:05 by cscelfo           #+#    #+#             */
/*   Updated: 2023/09/05 16:29:07 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_red_output(char *file, t_data *data, int append_or_not)
{
	int	open_flag;

	open_flag = append_or_not;
	if (data->outfile_fd > -1)
		close(data->outfile_fd);
	data->outfile_fd = open(file, O_WRONLY | O_CREAT | open_flag, 0644);
	if (data->outfile_fd == -1)
		ft_printf_fd(2, "racoonshell: %s: no such file or directory\n", file);
}

void	ft_red_input(char *file, t_data *data)
{
	if (data->infile_fd > -1)
		close(data->infile_fd);
	data->infile_fd = open(file, O_RDONLY);
	if (data->infile_fd == -1)
		ft_printf_fd(2, "racoonshell: %s: no such file or directory\n", file);
}
