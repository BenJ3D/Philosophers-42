# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 16:05:24 by cfatrane          #+#    #+#              #
#    Updated: 2022/06/14 12:47:22 by bducrocq         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary 

NAME = philo

# Path

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

CPPFLAGS = -I./includes/

HEADER = ./includes/philosophers.h


# Name

SRC_NAME =	test.c					\
			philo.c					\
			main.c					\
			error.c					\
			parsing.c				\
			tools.c					\
			check_arg.c				\
			routines.c				\
			message_philo.c			\
			time.c					\
			debug.c

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags

CC = gcc $(CFLAGS) $(SANITIZE) $(LLDBFLAG)

CFLAGS =# -Wall -Wextra -Werror
SANITIZE =# -fsanitize=address
LLDBFLAG = -g3

# Rules

all: $(NAME) 

# $(NAME): $(OBJ)
# ifeq ($(shell uname -s), Linux)
# 	@echo "\033[34mCreation of $(NAME) on linux ...\033[0m"
# 	@$(CC) $(OBJ) -o $@ -lpthread
# 	@echo "\033[32m$(NAME) created\n\033[0m"
# else
# 	@echo "\033[34mCreation of $(NAME) ...\033[0m"
# 	@$(CC) $(OBJ) -o $@
# 	@echo "\033[32m$(NAME) created\n\033[0m"
# endif

$(NAME): $(OBJ)
	@echo "\033[34mCreation of $(NAME) on linux ...\033[0m"
	@$(CC) $(OBJ) -o $@ -lpthread
	@echo "\033[32m$(NAME) created\n\033[0m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) ./Makefile
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CPPFLAGS) -o $@ -c $<

clean:
	@echo "\033[33mRemoval of .o files of $(NAME) ...\033[0m"
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "\033[31mFiles .o deleted\n\033[0m"

fclean: clean
	@echo "\033[33mRemoval of $(NAME)...\033[0m"
	@rm -rf $(NAME)
	@echo "\033[31mBinary $(NAME) deleted\n\033[0m"

re: fclean all

norme:
	norminette ./srcs/
	norminette ./includes/*.h


git:
	@git add .
	@printf "Message of the commit: " && read msg && git commit -m "$$msg"
	@git push

.PHONY: all, clean, fclean, re

#	@printf "\r\033[K\tCompilation de $(COLOR_PURPLE)$< ==> $@\$(COLOR_NORM)"