/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:30:19 by cscelfo           #+#    #+#             */
/*   Updated: 2023/08/21 17:56:17 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*!
 * @brief 
	This function will split a string into multiple based on a delimeter
	given as parameter.
 * @param s
	The string that will be checked.
 * @param c
	The delimeter used to divide multiple strings.
 * @return 
	The matrix where each block will have a string splitted from the
	original parameter.
*/

static char	*ft_char_to_str(char c)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (0);
	str[0] = c;
	return (str);
}

int	ft_countstr(char *s, char c)
{
	int	num_str;
	int	i;

	num_str = 0;
	i = 0;
	if (!s)
		return (num_str);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		num_str += 1;
		while (s[i] && s[i] != c)
			i++;
	}
	return (num_str);
}

char	**ft_split(char *s, char c)
{
	t_var		var;

	var.i = 0;
	var.k = 0;
	var.j = 0;
	var.trim = ft_strtrim(s, ft_char_to_str(c));
	if (!var.trim || !*var.trim)
		return (NULL);
	var.nb_str = ft_countstr(var.trim, c);
	var.arr_p = ft_calloc(var.nb_str + 1, sizeof(char *));
	while (var.i < var.nb_str)
	{
		if (var.trim[++var.j] == c || var.trim[var.j] == '\0')
		{
			var.arr_p[var.i++] = ft_substr(var.trim, var.k, var.j - var.k);
			while (var.trim[var.j] == c)
				var.j++;
			var.k = var.j;
		}
	}
	var.arr_p[var.i] = 0;
	ft_free((void **)&var.trim);
	return (var.arr_p);
}
