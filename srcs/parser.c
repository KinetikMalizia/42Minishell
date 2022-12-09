/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:36:38 by jcarlen           #+#    #+#             */
/*   Updated: 2022/11/21 12:08:01 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	split_inpt_2(int tab_size, char **tab, char *s, t_data *data);

static int	inpt_checker_1(char **str, t_data *data)
{
	int	i;

	i = 0;
	if (!ft_strcmp(str[i], "echo"))
		if (str[1])
			echo_prnt(&str[1], data);
	if (!ft_strcmp(str[i], "pwd"))
		printf("%s\n", data->path);
	if (!ft_strncmp(str[i], ".", 1) || !ft_strncmp(str[i], "/", 1))
		if (execute(str, data))
			return (1);
	if (!ft_strcmp(str[i], "env"))
		print_env(data);
	if (!ft_strcmp(str[i], "exit"))
		return (exit_checker(str, data));
	if (!ft_strcmp(str[i], "cd"))
		ft_cd(data->path, ft_strjoin("/", str[i + 1]), data);
	if (!ft_strcmp(str[i], "export"))
		while (i == 0 || (str[i] && str[i + 1]))
			export(data, str[++i]);
	i = 0;
	if (!ft_strcmp(str[i], "unset"))
		while (str[i + 1])
			unset(data, str[++i]);
	return (0);
}

int	inpt_checker(char **str, t_data *data)
{
	int	i;

	i = 0;
	if (!(str))
		return (0);
	if (is_builtin(str))
	{
		if (inpt_checker_1(str, data))
			return (1);
	}
	else
		if (is_function(str, data))
			return (1);
	return (0);
}

char	**split_inpt(char *s, t_data *data)
{
	int		tab_size;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	tab_size = count_args(s);
	tab = (char **)malloc(sizeof(char *) * (tab_size + 1));
	data->escape = malloc((tab_size + 1) * sizeof(t_escape));
	if (tab == NULL || data->escape == NULL)
		return (NULL);
	while (i < tab_size)
	{
		data->escape[i].space = 0;
		data->escape[i].escape = 0;
		++i;
	}
	i = 0;
	split_inpt_2(tab_size, tab, s, data);
	return (tab);
}

static void	split_inpt_2(int tab_size, char **tab, char *s, t_data *data)
{
	int	x;
	int	i;

	x = 0;
	i = 0;
	while (tab_size--)
	{
		while ((*s == ' ' || *s == '\t') && *s)
			s++;
		if (*s == '"' || *s == 39)
		{
			data->escape[i].escape = *s;
			x = 1;
		}
		if (*s + x != 0)
			tab[i++] = ft_substr(s + x, 0, arg_len(s));
		if (tab == NULL)
			return ;
		s += arg_len(s) + (2 * x);
		if (*s == ' ' && ft_pipetok(*s + 1))
			data->escape[i - 1].space = 1;
		x = 0;
	}
	tab[i] = NULL;
}

int	is_builtin(char **str)
{
	if (str[0] == 0)
		return (0);
	if (!ft_strcmp(str[0], "echo") || !ft_strcmp(str[0], "pwd")
		|| !ft_strncmp(str[0], ".", 1) || !ft_strcmp(str[0], "env")
		|| !ft_strcmp(str[0], "exit") || !ft_strcmp(str[0], "cd")
		|| !ft_strcmp(str[0], "export") || !ft_strcmp(str[0], "unset")
		|| !ft_strncmp(str[0], "/", 1))
	{
		return (1);
	}
	return (0);
}
