/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 10:42:34 by jcarlen           #+#    #+#             */
/*   Updated: 2022/09/06 13:13:35 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

long			ft_atol(const char *str);

static int		ft_strlen_nbr(const char *str);

long	ft_atol(const char *str)
{
	int			neg;
	long int	nb;

	nb = 0;
	neg = 1;
	while ((9 <= *str && *str <= 13) || *str == 32)
		++str;
	if (*str == '-')
	{
		neg *= -1;
		++str;
	}
	else if (*str == '+')
		++str;
	if (ft_strlen_nbr(str) > 19 && neg < 0)
		return (0);
	if (ft_strlen_nbr(str) > 19 && neg > 0)
		return (-1);
	while ('0' <= *str && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		++str;
	}
	return (nb * neg);
}

static int	ft_strlen_nbr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		++i;
	return (i);
}
