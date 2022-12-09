/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:36:02 by jcarlen           #+#    #+#             */
/*   Updated: 2021/11/01 13:36:07 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strdup(char *src);

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	copy = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (copy == 0)
		return (0);
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
