/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:36:21 by jcarlen           #+#    #+#             */
/*   Updated: 2021/11/01 13:36:23 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_calloc(size_t c, size_t n);

void	*ft_calloc(size_t c, size_t n)
{
	void	*ptr;

	ptr = malloc(c * n);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, c * n);
	return (ptr);
}
