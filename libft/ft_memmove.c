/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:53:55 by jcarlen           #+#    #+#             */
/*   Updated: 2021/10/26 16:53:58 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*pdst;
	char	*psrc;

	pdst = (char *)dst;
	psrc = (char *)src;
	if (src == dst)
		return (dst);
	if (psrc < pdst)
	{
		while (n--)
			*(pdst + n) = *(psrc + n);
		return (dst);
	}
	while (n--)
		*pdst++ = *psrc++;
	return (dst);
}
