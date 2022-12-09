/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:29:27 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/11/21 11:37:07 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	inpt_format_1(char *inpt, int *quotes, int *doubles, int *i);
static int	inpt_format_2(int quotes, int doubles);

int	inpt_format(char *inpt)
{
	int		i;
	int		quotes;
	int		doubles;

	i = 0;
	quotes = 0;
	doubles = 0;
	if (inpt == NULL)
		return (0);
	i = 0;
	while (inpt[i])
	{
		if (inpt_format_1(inpt, &quotes, &doubles, &i) == 0)
			return (0);
		i++;
	}
	return (inpt_format_2(quotes, doubles));
}

static int	inpt_format_1(char *inpt, int *quotes, int *doubles, int *i)
{
	char	c;

	if (inpt[*i] == '"' || inpt[*i] == '\'')
	{
		c = inpt[*i];
		if (c == '"')
			*doubles += 1;
		if (c == '\'')
			*quotes += 1;
		*i += 1;
		while (inpt[*i] && inpt[*i] != c)
			*i += 1;
		if (inpt[*i] == '"')
			*doubles += 1;
		if (inpt[*i] == '\'')
			*quotes += 1;
	}
	return (1);
}

static int	inpt_format_2(int quotes, int doubles)
{
	if (quotes % 2 || doubles % 2)
	{
		printf ("Synthax Error : %s\n", strerror(1));
		return (0);
	}
	return (1);
}

int	pipe_format(char *inpt, int i)
{
	int	pipes;

	pipes = 0;
	while (inpt[i + pipes] && ft_isprint(inpt[i + pipes]))
	{
		++pipes;
		if (!(ft_isprint(inpt[i + pipes])))
		{
			printf ("Synthax Error : %s\n", strerror(1));
			return (0);
		}
	}
	return (pipes);
}
