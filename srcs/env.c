/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:47:47 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/11/21 11:38:16 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	create_node_1(t_env	*new);

t_env	*create_node(const char *str)
{
	t_env	*new_node;
	int		n_size;
	int		c_size;

	n_size = 0;
	c_size = 0;
	while (str[n_size] && str[n_size] != '=')
		++n_size;
	new_node = malloc(sizeof(t_env));
	new_node->str = ft_strdup((char *)str);
	new_node->name = malloc(n_size);
	create_node_1(new_node);
	ft_strlcpy(new_node->name, str, n_size + 1);
	if (str[n_size] == '\0')
	{
		new_node->next = NULL;
		new_node->value = NULL;
		return (new_node);
	}
	while (str[c_size + n_size] != ' ' && str[c_size + n_size])
		++c_size;
	new_node->value = malloc(c_size);
	ft_strlcpy(new_node->value, &str[n_size + 1], c_size);
	new_node->next = NULL;
	return (new_node);
}

static void	create_node_1(t_env	*new)
{
	new->valid = 0;
	new->order = 0;
}

void	make_env(char **env, t_data *data)
{
	int		i;
	t_env	*prev;

	i = 0;
	prev = create_node(env[i]);
	data->env = prev;
	++i;
	while (env[i])
	{
		prev->next = create_node(env[i]);
		prev->valid = 1;
		prev = prev->next;
		++i;
	}
	prev->valid = 1;
}

void	print_env(t_data *data)
{
	t_env	*curr;

	curr = data->env;
	while (curr)
	{
		if (curr->valid)
			printf("%s=%s\n", curr->name, curr->value);
		curr = curr->next;
	}
	data->return_val = 0;
}

void	free_env(t_env *curr)
{
	t_env	*next;

	while (curr)
	{
		free(curr->str);
		free(curr->name);
		free(curr->value);
		next = curr->next;
		free(curr);
		curr = next;
	}
}
