/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:42:25 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/17 10:10:03 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		printf("\n");
		++i;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL || tab[0] == NULL)
		return ;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		++i;
	}
}

int	free_all(char **args, char *inpt, t_escape *escape)
{
	if (args != NULL)
	{
		free_tab(args);
		free(args);
	}
	if (escape)
		free(escape);
	if (inpt)
		free(inpt);
	return (0);
}

static void	exit_free_1(t_data *data, char **args, int exit_code)
{
	free(data->show);
	free_all(args, NULL, data->escape);
	free_env(data->env);
	free_tab(data->paths);
	free(data->paths);
	free(data->pipe);
	free(data->pwd);
	free(data->path);
	free(data->display_path);
	exit (exit_code);
}

void	exit_free(t_data *data, char **args)
{
	int	exit_code;

	exit_code = 0;
	if (args[1])
	{
		exit_code = exit_checker(args, data);
		if (exit_code == 1)
		{
			ft_putstr_fd("exit\n", 2);
			exit_code = (atoi(args[1]));
		}
		else
		{
			ft_putstr_fd("exit\n", 2);
			ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
		}
	}
	else
		ft_putstr_fd("exit\n", 2);
	exit_free_1(data, args, exit_code);
}
