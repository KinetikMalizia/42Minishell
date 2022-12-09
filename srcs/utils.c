/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:53:26 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/16 16:35:37 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*ft_envlast(t_env *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_env	*find_in(t_env	*lst, char	*str)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (!ft_isalnum(str[i]) && lst->name[i] == '\0')
			return (lst);
		if (lst->name[i] == str[i])
			++i;
		else
		{
			lst = lst->next;
			i = 0;
		}
	}
	return (lst);
}

int	exit_checker(char **str, t_data *data)
{
	int	i;

	i = 0;
	if (str[1])
	{
		while (str[1][i])
		{
			if (!('0' <= str[1][i] && str[1][i] <= '9'))
				return (255);
			++i;
		}
	}
	i = 0;
	while (str[i])
		++i;
	if (i > 2)
	{
		data->return_val = 1;
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (0);
	}
	return (1);
}
