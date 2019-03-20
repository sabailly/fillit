# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/28 13:51:05 by armoulin          #+#    #+#              #
#    Updated: 2019/03/20 13:27:49 by armoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

GRN		= "\x1B[32m"
RESET	= "\033[0m"

NAME	= fillit
LIB		= ./libft/libft.a
HEADER	= fillit.h

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRC		= parsing.c \
		  algo.c \
		  main.c

OBJ		= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	@make -C ./libft
	@echo -n 'Compiling	$(NAME)		-->	'
	@$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@
	@echo $(GRN)'Done !'$(RESET)

%.o:		%.c
	@$(CC) $(CFLAGS) -c $? -o $@

clean:
	@make clean -C ./libft
	@echo -n 'Removing	objects		-->	'
	@$(RM) $(OBJ)
	@echo $(GRN)'Done !'$(RESET)

fclean:		clean
	@make fclean -C ./libft
	@echo -n 'Removing	$(NAME)		-->	'
	@$(RM) $(NAME)
	@echo $(GRN)'Done !'$(RESET)

re:			fclean all
