/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:00:23 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/08 13:37:36 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_lexer(t_lexer *lexer)
{
	t_lexer		*tmp;
	int			i;
	int			n;

	n = 1;
	tmp = lexer;
	printf("\n");
	while (lexer)
	{
		printf("NODE [%d]\n", n);
		printf("___words:_________\n");
		i = -1;
		while (lexer->wrd[++i])
			printf("%s\n", lexer->wrd[i]);
		printf("___redirects:_____\n");
		i = -1;
		while (lexer->red[++i])
			printf("%s\n", lexer->red[i]);
		printf("__________________\n\n");
		lexer = lexer->next;
		n++;
	}
	lexer = tmp;
}
