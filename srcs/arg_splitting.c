/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_splitting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:24:17 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/21 12:24:24 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/minishell.h"

static int	arg_len_2(char *s);
static int	count_args_2(char *s, int i, int x, int words);

int	count_args(char *s)
{
	int	words;
	int	i;
	int	x;

	i = 0;
	x = 0;
	words = 0;
	return (count_args_2(s, i, x, words));
}

static int	count_args_2(char *s, int i, int x, int words)
{
	while (s[i])
	{
		if (s[i] == '"')
		{
			x++;
			while (s[i + x] && s[i + x] != '"')
				++x;
			if (s[i + x] == '"')
				words++;
			i++;
		}
		i = x + i;
		if (s[i - 1] == '"' && ft_isprint(s[i]))
			words++;
		if ((s[i] != ' ' && s[i] != '\t') && ((s[i - 1] == ' '
					|| s[i - 1] == '\t') || i == 0))
			words++;
		if (s[i] == '|' || s[i] == '>' || s[i] == '<')
			words += 2;
		if ((s[i] == '>' || s[i] == '<') && s[i] == s[i + 1])
			++i;
		i++;
		x = 0;
	}
	return (words);
}

int	arg_len(char *s)
{
	int		len;
	char	c;

	len = 0;
	if (*s == '"' || *s == 39)
	{
		c = *s;
		s++;
		while (*s != c)
		{
			s++;
			len++;
		}
		s++;
	}
	else
		len = arg_len_2(s);
	return (len);
}

static int	arg_len_2(char *s)
{
	int	len;

	len = 0;
	if (*s == '|' || *s == '>' || *s == '<')
	{
		len++;
		if (*s == s[1] && *s != '|')
		{
			len++;
			s++;
		}
		return (len);
	}
	while (*s && *s != ' ' && *s != '"'
		&& *s != '|' && *s != '>' && *s != '<')
	{
		len++;
		s++;
	}
	return (len);
}
