/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:56:51 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/16 16:35:29 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	print_exp(int o, t_env *head);
static void	find_order(t_env *head);

void	sort_print(t_env *env)
{
	t_env	*env2;
	t_env	*head;
	int		o;
	int		i;

	o = 0;
	i = 0;
	env2 = create_node(env->str);
	head = env2;
	env = env->next;
	while (env)
	{
		env2->next = create_node(env->str);
		env2 = env2->next;
		env2->order = 0;
		env = env->next;
		o++;
	}
	env2->next = NULL;
	find_order(head);
	print_exp(o, head);
	free_env(head);
}

static void	find_order(t_env *head)
{
	t_env	*env2;
	t_env	*env3;

	env2 = head;
	env3 = env2->next;
	while (env2)
	{
		if (ft_strcmp(env2->name, env3->name) > 0)
		{
			env2->order += 1;
		}
		env3 = env3->next;
		if (env3 == NULL)
		{
			env3 = head;
			env2 = env2->next;
		}
	}
}

static void	print_exp(int o, t_env *head)
{
	int		i;
	t_env	*env2;

	i = 0;
	env2 = head;
	while (i <= o)
	{
		while (env2->order != i)
			env2 = env2->next;
		printf("declare -x %s", env2->name);
		if (env2->value)
			printf("=\"%s\"", env2->value);
		printf("\n");
		++i;
		env2 = head;
	}
}
