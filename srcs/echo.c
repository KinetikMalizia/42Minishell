/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:47:55 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/21 11:59:45 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_putstr(char *str)
{
	int	count;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	count = 0;
	while (str[count])
		count++;
	write(1, str, count);
}

int	echo_prnt(char **args, t_data *data)
{
	int	i;
	int	slash;

	i = 0;
	slash = 1;
	if (args[0][0] == '-' && args[0][1] == 'n')
	{
		slash = 0;
		++i;
	}
	while (args[i] != NULL)
	{
		ft_putstr(args[i]);
		if (data->escape[i + 1].space == 1)
			write(1, " ", 1);
		i++;
	}
	if (slash)
		write(1, "\n", 1);
	data->return_val = 0;
	return (0);
}

void	pipe_type(char *str, t_data *data, int i)
{
	if (data->piped != 0)
		return ;
	if (data->escape[i].escape)
		return ;
	if (str[0] == '|')
		data->piped = 1;
	if (str[0] == '>')
	{
		if (str[1] == '>')
			data->piped = 3;
		else
			data->piped = 2;
	}
	if (str[0] == '<')
	{
		if (str[1] == '<')
			data->piped = 5;
		else
			data->piped = 4;
	}
}

/*
| = 1
> = 2
>> = 3
< = 4
<< = 5
*/