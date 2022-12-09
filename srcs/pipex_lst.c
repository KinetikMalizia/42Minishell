/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:16:56 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/04 10:42:46 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*n_cmd(char **str)
{
	t_cmd	*new;
	int		num_str;

	num_str = 0;
	while (str[num_str])
		++num_str;
	new = malloc(sizeof(t_cmd));
	new->next = NULL;
	new->pid = 0;
	new->val = calloc(num_str, sizeof(char *));
	new->in = 0;
	new->out = 0;
	return (new);
}

void	free_cmds(t_data	*data)
{
	t_cmd	*curr;
	t_cmd	*next;

	curr = data->pipe->h;
	data->pipe->err_out = 0;
	while (curr)
	{
		next = curr->next;
		if (curr->val)
		{
			free_tab(curr->val);
			free(curr->val);
		}
		free(curr);
		curr = next;
	}
}
