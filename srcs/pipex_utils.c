/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:23:30 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/16 16:35:55 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	split_and_fill(char **str, t_data *data, int i, int x);

int	ft_pipetok(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

int	fill_tab(char **str, t_data *data)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	data->pipe->in_double = 0;
	data->pipe->out_double = 0;
	if (data->pipe->h)
		data->pipe->h = NULL;
	while (str[i] != NULL)
	{
		while (str[i] != NULL && !ft_pipetok(str[i][0]))
			++i;
		if (str[i] == NULL)
			break ;
		split_and_fill(str, data, i, x);
		++i;
		x = i;
	}
	data->pipe->last_cmd = NULL;
	return (0);
}

/*split_and_fill peut etre simplifiée mais pas le time maintenant*/
static void	split_and_fill(char **str, t_data *data, int i, int x)
{
	if (str[i][0] == '<')
	{
		if (str[i][1] == '<')
			data->pipe->in_double = 1;
		split_tab_node(&str[x], data->pipe->last_cmd, data, '<');
	}
	if (str[i][0] == '|')
		split_tab_node(&str[x], data->pipe->last_cmd, data, '|');
	if (str[i][0] == '>')
	{
		if (str[i][1] == '>')
			data->pipe->out_double = 1;
		split_tab_node(&str[x], data->pipe->last_cmd, data, '>');
	}
}

int	pipe_checker(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[0][0] == '|')
		{
			ft_putstr_fd("error near unexpected token\n", STDERR_FILENO);
			return (1);
		}
		if (ft_pipetok(str[i][0]))
		{
			if (!str[i + 1] || ft_pipetok(str[i + 1][0]))
			{
				ft_putstr_fd("error near unexpected token\n", STDERR_FILENO);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
