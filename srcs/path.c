/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:07:19 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/21 11:44:04 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <fcntl.h>
#include <sys/stat.h>

void	path_update(t_data *data)
{
	t_env	*current;
	char	*old_path;
	char	*n_pwd;
	int		tmp;

	tmp = 0;
	current = data->env;
	old_path = data->path;
	data->path = malloc(600);
	getcwd(data->path, 600);
	data->path = ft_realloc(data->path, ft_strlen(data->path) + 1);
	if (data->display_path)
		free(data->display_path);
	data->display_path = ft_strjoin(data->path, " $>");
	n_pwd = ft_strjoin("PWD=", data->path);
	tmp = data->return_val;
	export(data, n_pwd);
	data->return_val = tmp;
	data->home = find_in(data->env, "HOME=");
	free_tab(data->paths);
	free(data->paths);
	data->paths = path_split(data->env);
	free(old_path);
	free(n_pwd);
}
