/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:47:55 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/16 16:35:33 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*cleaner_3(char *str, char *temp, t_env *env, int *i);

static char	*cleaner_1(char *str, char *temp, int *i, t_data *data)
{
	t_env	*env;

	env = data->env;
	if (str[*i] == '$' && str[*i + 1] == '?')
	{
		*i += 2;
		return (ft_itoa(data->return_val));
	}
	if (str[*i] == '$')
	{
		temp = cleaner_3(str, temp, env, i);
		*i += 1;
	}
	return (temp);
}

static char	*cleaner_2(char *str, t_data *data, char *temp, int i)
{
	t_env	*env;
	int		x;

	x = 0;
	ft_strlcpy(temp, str, i + 1);
	while (str[i])
	{
		env = data->env;
		while (str[i + x] && str[i + x] != '$')
			++x;
		if (str[i] != '$')
		{
			temp = ft_realloc(temp, ft_strlen(temp) + x + 1);
			ft_strlcat(temp, &str[i], ft_strlen(temp) + x + 1);
			i += x;
			continue ;
		}
		temp = cleaner_1(str, temp, &i, data);
		while (str[i] && ft_isalnum(str[i]))
			i += 1;
		x = 0;
	}
	free(str);
	return (temp);
}

static char	*cleaner_3(char *str, char *temp, t_env *env, int *i)
{
	if (str[*i + 1] == '\'' || str[*i + 1] == ' ' || str[*i + 1] == '\0')
		ft_strlcat(temp, "$", ft_strlen(temp) + 2);
	else
	{
		env = find_in(env, &str[*i + 1]);
		if (str[*i] == '$' && env)
		{
			temp = ft_realloc(temp, ft_strlen(temp)
					+ ft_strlen(env->value) + 1);
			ft_strlcat(temp, env->value, ft_strlen(temp)
				+ ft_strlen(env->value) + 1);
		}
	}
	return (temp);
}

char	*cleaner(char *str, t_data *data, int index)
{
	int		i;
	char	*temp;

	i = 0;
	pipe_type(str, data, index);
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] && data->escape[index].escape != '\'')
		{
			temp = malloc(i + 2);
			if (!temp)
				return (0);
			return (cleaner_2(str, data, temp, i));
		}
		if (str[i] == 92)
			i++;
		i++;
	}
	return (str);
}
