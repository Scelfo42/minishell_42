/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:30:49 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/04 11:30:50 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*ft_init_history(t_data *data)
{
	char	*line;

	data->history = ft_strjoin(data->pwd, "/.minishell_history");
	data->history_fd = open(data->history, O_RDWR | O_CREAT, 0644);
	line = get_next_line(data->history_fd);
	if (!line)
	{
		free(line);
		return (data);
	}
	else
	{
		while (line)
		{
			line[ft_strlen(line) - 1] = 0;
			add_history(line);
			free(line);
			line = NULL;
			line = get_next_line(data->history_fd);
		}
	}
	free(line);
	return (data);
}

void	ft_miniputstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
