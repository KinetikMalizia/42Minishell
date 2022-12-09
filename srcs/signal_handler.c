/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:55:09 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/16 16:35:30 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_signals(int signo)
{
	if (signo == SIGINT)
	{
		if (g_status != WORKING)
		{
			write(1, "\n", 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
		}
		if (g_status == WORKING)
		{
			write(1, "^C\n", 3);
			g_status = 130;
		}
	}
	if (signo == SIGQUIT)
	{
		if (g_status == WORKING)
		{
			g_status = 131;
			printf("^\\Quit: 3\n");
		}
	}
}

int	set_signal(void)
{
	if (signal(SIGINT, handle_signals) == SIG_ERR)
	{
		printf("failed to register signal\n");
		return (0);
	}
	if (signal(SIGQUIT, handle_signals) == SIG_ERR)
	{
		printf("failed to register signal\n");
		return (0);
	}
	return (1);
}
