/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:10:21 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/16 16:35:32 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	setup_pipe_struct(t_data *data);

void	data_init(t_data *data)
{
	data->pwd = getcwd(NULL, 0);
}

void	main_init(char **env, t_data *data)
{
	data->path = NULL;
	data->paths = NULL;
	data->display_path = NULL;
	data->return_val = 0;
	make_env(env, data);
	setup_pipe_struct(data);
	set_signal();
	data->show = malloc(sizeof(struct termios));
	setup_term(data->show);
	data->home = find_in(data->env, "HOME");
}

static int	setup_pipe_struct(t_data *data)
{
	data->pipe = malloc (sizeof(t_pipe));
	if (data->pipe == NULL)
		return (1);
	data->pipe->err_out = 0;
	return (0);
}
