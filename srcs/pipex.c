/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:02:27 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/16 16:35:50 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	close_pipes(t_cmd *curr);
static void	do_waits(t_data *data);

static void	init_pipes(t_data *data)
{
	t_cmd	*curr;
	int		fd[2];

	curr = data->pipe->h;
	while (curr->next)
	{
		pipe(fd);
		if (!curr->out)
			curr->out = fd[1];
		else
			close(fd[1]);
		if (!curr->next->in)
			curr->next->in = fd[0];
		else
			close(fd[0]);
		curr = curr->next;
	}
	if (!curr->out)
		curr->out = 1;
}

int	pipe_loop(char **str, t_data *data)
{
	t_cmd	*curr;

	fill_tab(str, data);
	curr = data->pipe->h;
	init_pipes(data);
	while (curr)
	{
		if (curr->in < 0 || curr->out < 0)
		{
			curr = curr->next;
			continue ;
		}
		curr->pid = fork();
		if (curr->pid == 0)
			child_pro(data, curr);
		curr = curr->next;
	}
	do_waits(data);
	free_cmds(data);
	return (0);
}

int	child_pro(t_data *data, t_cmd *curr)
{
	int	old_stdin;
	int	old_stdout;

	old_stdin = dup(STDIN_FILENO);
	old_stdout = dup(STDOUT_FILENO);
	if (curr->in > 2)
		dup2(curr->in, STDIN_FILENO);
	if (curr->out > 2)
		dup2(curr->out, STDOUT_FILENO);
	close_pipes(data->pipe->h);
	inpt_checker(curr->val, data);
	exit(0);
}

static void	close_pipes(t_cmd *curr)
{
	while (curr)
	{
		if (curr->in > 2)
			close(curr->in);
		if (curr->out > 2)
			close(curr->out);
		curr = curr->next;
	}
}

static void	do_waits(t_data *data)
{
	t_cmd	*curr;

	curr = data->pipe->h;
	close_pipes(curr);
	while (curr)
	{
		waitpid(curr->pid, &data->return_val, 0);
		curr = curr->next;
	}
}
