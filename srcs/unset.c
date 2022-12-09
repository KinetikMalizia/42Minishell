/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:44:21 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/21 10:58:07 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_env	*unset_1(t_env *uns, t_env *prev, char *str)
{
	int	i;

	i = 0;
	while (uns)
	{
		if (!ft_isalnum(str[i]) && uns->name[i] == '\0')
			break ;
		if (uns->name[i] == str[i])
			++i;
		else
		{
			prev = uns;
			uns = uns->next;
			i = 0;
		}
	}
	return (prev);
}

void	unset_free(t_env *uns)
{
	if (!uns)
		return ;
	if (uns->str)
		free(uns->str);
	if (uns->value)
		free(uns->value);
	if (uns->name)
		free(uns->name);
	free(uns);
}

void	unset(t_data *data, char *str)
{
	t_env	*uns;
	t_env	*prev;

	uns = data->env;
	prev = NULL;
	if (!str)
		return ;
	prev = unset_1(uns, prev, str);
	uns = prev->next;
	if (!uns)
	{
		data->return_val = 1;
		return ;
	}
	prev->next = uns->next;
	unset_free(uns);
	data->return_val = 0;
}
