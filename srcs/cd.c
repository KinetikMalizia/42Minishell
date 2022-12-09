/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:55:26 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/11/21 11:04:32 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	ft_cd_1(char *new, t_data *data);

int	ft_cd(char *current, char *new, t_data *data)
{
	char	*free_cpy;
	char	*o_pwd;

	o_pwd = ft_strjoin("OLDPWD=", current);
	export(data, o_pwd);
	free(o_pwd);
	free_cpy = new;
	if (*new == '\0')
		return (ft_cd_1(new, data));
	if (new[1] != '/')
		new = ft_strjoin(current, new);
	if (chdir(new) < 0)
	{
		perror("Error ");
		if (free_cpy)
			free(free_cpy);
		if (new)
			free(new);
		data->return_val = 1;
		return (0);
	}
	if (new[1] != '/')
		free(free_cpy);
	free(new);
	return (data->return_val = 0);
}

static int	ft_cd_1(char *new, t_data *data)
{
	data->home = find_in(data->env, "HOME");
	if (data->home == NULL)
	{
		ft_putstr_fd("cd: home not set\n", 2);
		free(new);
		return (1);
	}
	if (chdir(data->home->value) < 0)
	{
		perror("Error ");
		data->return_val = 1;
		free(new);
		return (0);
	}
	else
		data->return_val = 0;
	free(new);
	return (1);
}
