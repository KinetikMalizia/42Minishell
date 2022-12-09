# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmalizia <fmalizia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 13:51:43 by fmalizia          #+#    #+#              #
#    Updated: 2022/11/21 10:47:56 by fmalizia         ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

SRC_DIR := srcs
OBJ_DIR := objs
BIN_DIR := .
USERNAME = $(USER)

NAME := minishell
SRC	:=	srcs/echo.c \
		srcs/init.c \
		srcs/main.c \
		srcs/parser.c \
		srcs/path.c \
		srcs/env.c \
		srcs/cd.c \
		srcs/export.c \
		srcs/utils.c \
		srcs/pipex.c \
		srcs/signal_handler.c \
		srcs/format.c \
		srcs/arg_splitting.c \
		srcs/execute.c \
		srcs/pipex_utils.c \
		srcs/cleaner.c \
		srcs/general_utils.c \
		srcs/pipex_lst.c \
		srcs/pipex_utils_2.c \
		srcs/split_tab_node.c \
		srcs/split_tab_node_u.c \
		srcs/export_print.c \
		srcs/unset.c \

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT = libft/

CFLAGS := -Wall -Werror -Wextra -g

GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

RDLINC	=	-I/Users/${USERNAME}/homebrew/opt/readline/include
LIBRDL	=	-L/Users/${USERNAME}/homebrew/opt/readline/lib -lreadline

all: $(NAME)

start:
	@printf "$(GR)Compiling Minishell\n$(RE)"

$(NAME): libft start $(OBJ) | $(BIN_DIR) 
	@printf '\033[8;50;150t'
	@$(CC) $(OBJ) -L$(LIBFT) -lft $(LIBRDL) $(CFLAGS) -o $(NAME)
	@printf "$(GR)100%%  => SUCCESS\n$(RC)"
	@tput setaf 2; cat includes/art; tput setaf default
	@printf "$(GR)\nPress Any Key To Continue...\n$(RC)"
	@if bash includes/bash_wait.sh; then echo "minishell terminated"; fi

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GR)///$(RC)"

$(BIN_DIR) $(OBJ_DIR):
	@mkdir -p $@

libft:
	@ $(MAKE) bonus -C $(LIBFT)

.PRECIOUS: minishell

clean:
	@$(RM) -r $(OBJ_DIR)
	@printf "$(YE)** Deleting Objects **\n$(RC)"

fclean: clean
	@$(RM) -r $(NAME)
	@printf "$(YE)** Deleting Binary  **\n$(RC)"

reset: fclean
	@ $(MAKE) fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean start rules libft reset
