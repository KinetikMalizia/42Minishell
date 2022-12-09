/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:59:45 by jcarlen           #+#    #+#             */
/*   Updated: 2021/10/26 11:59:51 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memset(void *b, int c, size_t len);

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = c;
		i++;
	}
	return (b = p);
}
