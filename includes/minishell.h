/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:59:50 by fmalizia          #+#    #+#             */
/*   Updated: 2022/11/16 16:35:42 by fmalizia         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <termios.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

# define WAITING 1
# define PARSING 2
# define WORKING 3
# define ERROR 4

int	g_status;

typedef struct s_b{
	int		i;
	int		x;
	char	type;
	char	**str;
}				t_b;

typedef struct s_env {
	char			*str;
	char			*name;
	char			*value;
	int				valid;
	int				order;
	struct s_env	*next;
}				t_env;

typedef struct s_cmd{
	char			**val;
	int				in;
	int				out;
	int				pid;
	int				pfd[2];
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_escape {
	int		escape;
	int		space;
}				t_escape;

typedef struct s_pipe {
	t_cmd	*h;
	t_cmd	*last_cmd;
	int		err_out;
	int		in_double;
	int		out_double;
}				t_pipe;

typedef struct s_data {
	int				pipefd[2];
	char			*pwd;
	char			*path;
	char			*display_path;
	t_env			*env;
	char			***envp;
	char			*esc;
	char			**paths;
	int				return_val;
	int				piped;
	t_escape		*escape;
	t_pipe			*pipe;
	t_env			*home;
	struct termios	*show;
}				t_data;

void	rl_replace_line(const char *text, int clear_undo);
char	**split_inpt(char *s, t_data *data);
char	*ft_strtok(char *str, char *limit);
void	data_init(t_data *data);
int		echo_prnt(char **args, t_data *data);
int		inpt_checker(char **str, t_data *data);
void	path_update(t_data *data);
void	print_tab(char **tab);
t_env	*create_node(const char *str);
int		ft_cd(char *current, char *new, t_data *data);
void	make_env(char **env, t_data *data);
void	print_env(t_data *data);
void	free_tab(char **tab);
t_env	*ft_envlast(t_env *lst);
int		env_format(char *str);
void	export(t_data *data, char *str);
t_env	*find_in(t_env	*lst, char	*str);
void	change_val(t_env *node, char *str);
char	**ft_pipex(char **str, t_data *data);
void	handle_signals(int signo);
int		set_signal(void);
void	unset(t_data *data, char *str);
int		inpt_format(char *inpt);
int		pipe_format(char *inpt, int i);
char	*cleaner(char *str, t_data *data, int i);
int		arg_len(char *s);
int		count_args(char *s);
int		execute(char **str, t_data *data);
int		is_function(char **str, t_data *data);
int		is_builtin(char **str);
char	**path_split(t_env *env);
int		split_tab(char **str, char **before, char **after);
int		ft_pipe(char **str, t_data *data);
int		free_all(char **args, char *inpt, t_escape *escape);
int		parent_pro(int ch_pid, t_data *data);
int		child_pro(t_data *data, t_cmd *curr);
void	main_init(char **env, t_data *data);
void	pipe_type(char *str, t_data *data, int index);
void	setup_term(struct termios *show);
int		ft_pipetok(char c);
int		fill_tab(char **str, t_data *data);
int		open_outfile(t_data *data, int *out_fd, char *str);
int		open_infile(t_data *data, int *in_fd, char *str);
t_cmd	*n_cmd(char **str);
int		split_tab_node(char **str, t_cmd *before, t_data *data, char type);
void	print_all_cmd(t_data *data);
int		pipe_loop(char **str, t_data *data);
void	free_cmds(t_data	*data);
void	exit_free(t_data *data, char **args);
void	free_env(t_env *curr);
int		do_heredoc(char *str, int	*in_fd);
int		pipe_checker(char **str);
int		exit_checker(char **str, t_data *data);
void	sort_print(t_env *env);
//void	sort_export(t_env *env, t_data *data);

/* utils for split_node */

int		do1(t_cmd *before, char **str, int x, int i);
int		do2(t_data *data, t_cmd *before, t_b *b);
void	do3(t_data *data, t_cmd *before, char type, int x);
void	set_b(char type, char **str, t_b *b);

/////////////
//void	check_leaks(void);

#endif