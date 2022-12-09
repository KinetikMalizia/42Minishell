/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <jeancarlen@tudnt.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:54:59 by jcarlen           #+#    #+#             */
/*   Updated: 2022/11/14 10:278:28 by marvin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n);

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (dst[j] && j < n)
		j++;
	while (src[k] && ((j + k + 1) < n))
	{
		dst[j + k] = src[k];
		k++;
	}
	if (j != n)
		dst[j + k] = '\0';
	return (j + ft_strlen(src));
}
