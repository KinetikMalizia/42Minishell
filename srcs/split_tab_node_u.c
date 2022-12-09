/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tab_node_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:44:24 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/15 13:45:39 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	do1(t_cmd *before, char **str, int x, int i)
{
	if (before->next == NULL)
		before->next = n_cmd(str);
	before->next->val[x] = ft_strdup(str[i]);
	if (before->next->val[x] == NULL)
		return (1);
	return (0);
}

int	do2(t_data *data, t_cmd *before, t_b *b)
{
	if (b->type == '>')
		if (open_outfile(data, &before->out, b->str[b->i]))
			before->out = -1;
	if (b->type == '<')
		if (open_infile(data, &before->in, b->str[b->i]))
			before->in = -1;
	if (b->type == '<' || b->type == '>')
	{
		while (before->val[b->x])
			b->x += 1;
		b->type = '$';
		b->i += 1;
		return (1);
	}
	if (b->type == '$')
		before->val[b->x] = ft_strdup(b->str[b->i]);
	return (0);
}

void	do3(t_data *data, t_cmd *before, char type, int x)
{
	if (type == '|')
	{
		if (before->next)
			before->next->val[x] = NULL;
		data->pipe->last_cmd = before->next;
	}
	else
		data->pipe->last_cmd = before;
	data->pipe->out_double = 0;
	data->pipe->in_double = 0;
}

void	set_b(char type, char **str, t_b *b)
{
	b->x = 0;
	b->i = 0;
	b->str = str;
	b->type = type;
}
