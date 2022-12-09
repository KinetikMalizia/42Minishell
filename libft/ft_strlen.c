/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:57:45 by jcarlen           #+#    #+#             */
/*   Updated: 2021/10/26 11:57:48 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlen(const char *s);

size_t	ft_strlen(const char *s)
{
	int			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
