/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:49:11 by jcarlen           #+#    #+#             */
/*   Updated: 2022/11/21 12:19:04 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	setup_term(struct termios *show)
{
	struct termios	attr;

	tcgetattr(STDIN_FILENO, show);
	tcgetattr(STDIN_FILENO, &attr);
	attr.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &attr);
}

static char	*set_and_get(t_data *data)
{
	char	*inpt;

	inpt = NULL;
	data->piped = 0;
	path_update(data);
	if (g_status > 4)
		data->return_val = g_status;
	g_status = WAITING;
	signal(SIGQUIT, SIG_IGN);
	inpt = readline(data->display_path);
	g_status = PARSING;
	if (inpt && ft_isprint(inpt[0]))
		add_history(inpt);
	return (inpt);
}

static char	**clean_args(t_data *data, char *inpt)
{
	int		i;
	char	**args;

	i = 0;
	args = split_inpt(inpt, data);
	while (args[i])
	{
		args[i] = cleaner(args[i], data, i);
		i++;
	}
	g_status = WORKING;
	signal(SIGQUIT, handle_signals);
	return (args);
}

static int	run_shell(t_data *data, char **args, char *inpt)
{
	if (data->piped)
	{
		if (!pipe_checker(args))
		{
			if (pipe_loop(args, data))
			{
				free_all(args, inpt, data->escape);
				return (0);
			}
		}
	}
	else if (inpt_checker(args, data))
		exit_free(data, args);
	free_all(args, NULL, data->escape);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*inpt;
	char	**args;

	(void) ac;
	(void) av;
	args = NULL;
	inpt = NULL;
	data.envp = &env;
	main_init(env, &data);
	while (1)
	{
		inpt = set_and_get(&data);
		if (inpt == NULL)
			return (0);
		if (inpt_format(inpt))
		{
			args = clean_args(&data, inpt);
			if (!run_shell(&data, args, inpt))
				return (0);
		}
		free(inpt);
	}
	exit(EXIT_FAILURE);
}
