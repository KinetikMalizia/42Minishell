/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:40:15 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/21 10:47:42 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	export_1(t_env *env, char *str, t_env *new, int ret)
{
	t_env	*last;

	new = create_node(str);
	if (ret == 1)
		new->valid = 1;
	last = ft_envlast(env);
	while (env->next != last)
		env = env->next;
	env->next = new;
	new->next = last;
}

void	export(t_data *data, char *str)
{
	t_env	*env;
	t_env	*new;
	t_env	*last;
	int		ret;

	last = NULL;
	env = data->env;
	data->return_val = 0;
	ret = env_format(str);
	if (ret)
	{
		new = find_in(env, str);
		if (!new)
			export_1(env, str, new, ret);
		else
			change_val(new, str);
	}
	else if (str == NULL)
		sort_print(env);
	else
	{
		data->return_val = 1;
		printf ("Error : %s\n", strerror(22));
	}
}

int	env_format(char *str)
{
	int	i;

	i = 0;
	if (!str || ft_isdigit((int)str[0]) || str[0] == '?')
		return (0);
	while (str[i] != '=')
	{
		if (!ft_isprint(str[i]) || !ft_isalnum(str[i]))
		{
			if (str[i] == '\0')
				return (2);
			return (0);
		}
		++i;
	}
	return (1);
}

void	change_val(t_env *node, char *str)
{
	int		n_size;
	int		c_size;

	n_size = 0;
	c_size = 0;
	if (node->str)
		free(node->str);
	node->str = ft_strdup(str);
	while (str[n_size] != '=')
		++n_size;
	while (str[c_size + n_size] && str[c_size + n_size] != ' ')
		++c_size;
	if (node->value)
		free(node->value);
	node->value = malloc(c_size);
	ft_strlcpy(node->value, &str[n_size + 1], c_size);
	node->valid = 1;
}
