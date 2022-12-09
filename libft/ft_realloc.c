/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeancarlen <jeancarlen@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:57:26 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/14 10:10:20 by jeancarlen       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static char	*ft_strcpy(char *dest, char *src);

char	*ft_realloc(char *org, int n_size)
{
	char	*new;

	new = malloc(n_size);
	if (!new)
		return (NULL);
	ft_strcpy(new, org);
	if (org)
		free (org);
	return (new);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
