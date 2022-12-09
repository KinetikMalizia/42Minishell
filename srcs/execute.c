/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:27:55 by jeancarlen        #+#    #+#             */
/*   Updated: 2022/11/16 16:35:26 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	execute(char **str, t_data *data)
{
	pid_t	childpid;

	(void) data;
	childpid = fork();
	if (childpid == 0)
	{
		if (execve(*str, str, data->envp[0]) == -1)
			printf ("Error : %s\n", strerror(2));
		return (1);
	}
	else
		waitpid(childpid, &(data->return_val), 0);
	if (WIFEXITED(data->return_val))
		data->return_val = WEXITSTATUS(data->return_val);
	return (0);
}

static int	is_function_2(char **str, t_data *data)
{
	int		i;
	char	*address;

	i = 0;
	while (data->paths[i])
	{
		address = ft_strdup(data->paths[i]);
		address = ft_realloc(address,
				ft_strlen(address) + ft_strlen(str[0]) + 3);
		ft_strlcat(address, "/", ft_strlen(address) + ft_strlen(str[0]) + 3);
		ft_strlcat(address, *str, ft_strlen(address) + ft_strlen(str[0]) + 2);
		if (execve(address, &str[0], NULL) == -1)
			i++;
		free(address);
	}
	printf ("Error : %s\n", strerror(22));
	return (1);
}

int	is_function(char **str, t_data *data)
{
	pid_t	childpid;

	childpid = fork();
	if (childpid == 0)
	{
		is_function_2(str, data);
		exit (127);
	}
	else
		waitpid(childpid, &(data->return_val), 0);
	if (WIFEXITED(data->return_val))
		data->return_val = WEXITSTATUS(data->return_val);
	return (0);
}

char	**path_split(t_env *env)
{
	char	**ret_tab;
	char	*str;

	str = NULL;
	env = find_in(env, "PATH");
	if (env)
		str = ft_strdup(env->value);
	else
		str = ft_strdup("");
	ret_tab = ft_split(str, ':');
	free(str);
	return (ret_tab);
}
