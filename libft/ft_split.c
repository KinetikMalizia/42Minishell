/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:50:25 by jcarlen           #+#    #+#             */
/*   Updated: 2021/11/04 11:50:28 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char			**ft_split(char const *s, char c);

static int		count_words(char const *s, char c);

static int		wordlen(char const *s, char c);

void	ft_free(char **result, int i)
{
	while (i--)
		free(result[i]);
	free(result);
	return ;
}

static int	count_words(char const *s, char c)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (count);
}

static int	wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char		**t;
	int			nb_words;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	nb_words = count_words((const char *)s, c);
	t = malloc(sizeof(char *) * (nb_words + 1));
	if (!t)
		return (NULL);
	while (i < nb_words)
	{
		while (*s == c && *s != '\0')
			s++;
		t[i] = ft_substr((const char *)s, 0, wordlen((const char *)s, c));
		if (t[i] == NULL)
			ft_free(t, i);
		s = s + wordlen((const char *)s, c);
		i++;
	}
	t[i] = NULL;
	return (t);
}
