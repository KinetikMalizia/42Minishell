/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:58:17 by jcarlen           #+#    #+#             */
/*   Updated: 2021/10/26 14:58:21 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_bzero(void *b, size_t len);

void	ft_bzero(void *b, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = 0;
		i++;
	}
	b = p;
}
