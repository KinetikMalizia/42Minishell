/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tab_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:04:41 by jcarlen           #+#    #+#             */
/*   Updated: 2022/11/15 13:45:52 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_cmd	*split_tabb4(char **str, t_data *data, int *i)
{
	t_cmd	*before;

	before = n_cmd(str);
	if (data->pipe->h == NULL)
		data->pipe->h = before;
	while (str[*i] && (!ft_pipetok(str[*i][0])))
	{
		before->val[*i] = ft_strdup(str[*i]);
		if (before->val[*i] == NULL)
			return (NULL);
		*i += 1;
	}
	before->val[*i] = NULL;
	return (before);
}

int	split_tab_node(char **str, t_cmd *before, t_data *data, char type)
{
	t_b	b;

	set_b(type, str, &b);
	if (before == NULL)
	{
		before = split_tabb4(str, data, &b.i);
		if (before == NULL)
			return (1);
	}
	else
		while (str[b.i] && (!ft_pipetok(str[b.i][0])))
			b.i += 1;
	b.i += 1;
	while (str[b.i] && !ft_pipetok(str[b.i][0]))
	{
		if (b.type == '|')
			if (do1(before, str, b.x, b.i))
				return (1);
		if (do2(data, before, &b))
			continue ;
		b.i += 1;
		b.x += 1;
	}
	do3(data, before, type, b.x);
	return (0);
}
