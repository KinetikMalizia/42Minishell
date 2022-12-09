/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:50:43 by jcarlen           #+#    #+#             */
/*   Updated: 2021/11/04 11:50:44 by jcarlen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_itoa(int n);

size_t	nblen(int nbr);

size_t	nblen(int nbr)
{
	int	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < len)
		len += 1;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	n_size;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_size = nblen(n);
	str = (char *)malloc(sizeof(char) * (n_size + 1));
	if (str == 0)
		return (0);
	str[n_size] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i += 1;
	}
	while (i < n_size--)
	{
		str[n_size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
