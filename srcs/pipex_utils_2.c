/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:14:36 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/21 09:57:54 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	open_infile(t_data *data, int *in_fd, char *str)
{
	if (*in_fd)
		close(*in_fd);
	if (str && !data->pipe->in_double)
	{
		*in_fd = open(str, O_RDONLY);
		if (*in_fd < 0)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(str);
			data->pipe->err_out = 1;
			return (1);
		}
	}
	else if (str != NULL && data->pipe->in_double)
		do_heredoc(str, in_fd);
	return (0);
}

int	open_outfile(t_data *data, int *out_fd, char *str)
{
	if (*out_fd)
		close(*out_fd);
	if (str && !data->pipe->out_double)
	{
		*out_fd = open(str, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (*out_fd < 0)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(str);
			return (1);
		}
	}
	else if (str != NULL && data->pipe->out_double)
	{
		*out_fd = open(str, O_RDWR | O_CREAT | O_APPEND, 0644);
		if (*out_fd < 0)
		{
			ft_putstr_fd("minishell: ", 2);
			perror(str);
			return (1);
		}
	}
	return (0);
}

int	do_heredoc(char *str, int	*in_fd)
{
	int		fd[2];
	char	*line;

	if (str == NULL)
		return (1);
	pipe(fd);
	while (1)
	{
		line = readline("> ");
		if (line == NULL || !(ft_strcmp(str, line)))
			break ;
		ft_putendl_fd(line, fd[1]);
	}
	close(fd[1]);
	*in_fd = fd[0];
	return (0);
}

void	print_all_cmd(t_data *data)
{
	t_cmd	*curr;
	int		i;

	curr = data->pipe->h;
	i = 0;
	while (curr)
	{
		printf("infile: %d", curr->in);
		printf("	outfile: %d", curr->out);
		printf("	value: ");
		i = 0;
		while (curr->val[i])
			printf("%s ", curr->val[i++]);
		printf("\n");
		curr = curr->next;
	}
}
