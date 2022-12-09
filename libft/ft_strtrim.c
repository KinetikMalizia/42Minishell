/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:50:10 by jcarlen           #+#    #+#             */
/*   Updated: 2021/11/04 11:50:12 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"
#include<stdio.h>

char	*ft_strtrim(char const *s1, char const *set);

int		is_set(char c, char const *set);

int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*rtn;

	if (!s1 || !set)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1);
	while (is_set(s1[start], set) == 0)
		start++;
	if (start == ft_strlen(s1))
	{
		rtn = ft_substr(s1, start, end - start);
		return (rtn);
	}
	while (is_set(s1[end - 1], set) == 0)
		end--;
	rtn = ft_substr(s1, start, end - start);
	return (rtn);
}
