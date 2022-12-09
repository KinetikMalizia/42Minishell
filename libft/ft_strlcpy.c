/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:52:32 by jcarlen           #+#    #+#             */
/*   Updated: 2021/10/27 10:52:39 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcpy( char *dst, const char *src, size_t n);

size_t	ft_strlcpy( char *dst, const char *src, size_t n)
{
	size_t	slen;
	size_t	i;

	i = 0;
	slen = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (!n)
		return (slen);
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	if (n <= slen)
		dst[n - 1] = '\0';
	else if (n != 0)
		dst[i] = '\0';
	return (slen);
}
