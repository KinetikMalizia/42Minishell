# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 13:52:25 by jcarlen           #+#    #+#              #
#    Updated: 2022/09/07 13:54:38 by jcarlen          ###   ########.ch        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

GR = \033[32;1m
CY = \033[36;1m
RC = \033[0m
YE	= \033[33;1m

SRCS = ft_atoi.c \
	ft_atol.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strcmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_realloc.c \

OBJS = $(SRCS:.c=.o)

BONUS	= ft_lstsize.c ft_lstnew.c ft_lstadd_front.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = $(BONUS:.c=.o)

$(NAME): $(OBJS)
		@printf "\n $(RC)"
		@ar rcs $(NAME) $(OBJS)

%.o : %.c
		@$(CC) $(CFLAGS) $< -c
		@printf "$(GR)/"

all: $(NAME)
	@echo "$(NAME) created"

clean:
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@ printf "$(YE)** Deleting Libft   **\n$(RC)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus: start $(OBJS) $(BONUS_OBJS)
		@printf "100%%  => SUCCESS\n$(RC)"
		@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

start:
		@printf "$(GR)Compiling Libft\n"