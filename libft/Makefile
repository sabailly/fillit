# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: armoulin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 13:51:05 by armoulin          #+#    #+#              #
#    Updated: 2019/01/31 14:41:23 by armoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

GRN			= "\x1B[32m"
RESET		= "\033[0m"

NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC			= ft_memset.c		ft_bzero.c		ft_memcpy.c \
			  ft_memccpy.c		ft_memmove.c	ft_memchr.c \
			  ft_memcmp.c		ft_strlen.c		ft_strdup.c \
			  ft_strcpy.c		ft_strncpy.c	ft_strcat.c \
			  ft_strncat.c		ft_strlcat.c	ft_strchr.c \
			  ft_strrchr.c		ft_strstr.c		ft_strnstr.c \
			  ft_strcmp.c		ft_strncmp.c	ft_atoi.c \
			  ft_isalpha.c		ft_isdigit.c	ft_isalnum.c \
			  ft_isascii.c		ft_isprint.c	ft_toupper.c \
			  ft_tolower.c		ft_memalloc.c	ft_memdel.c \
			  ft_strnew.c		ft_strdel.c		ft_strclr.c \
			  ft_striter.c		ft_striteri.c	ft_strmap.c \
			  ft_strmapi.c		ft_strequ.c		ft_strnequ.c \
			  ft_strsub.c		ft_strjoin.c	ft_strtrim.c \
			  ft_strsplit.c		ft_itoa.c		ft_putchar.c \
			  ft_putstr.c		ft_putendl.c	ft_putnbr.c \
			  ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c \
			  ft_putnbr_fd.c	ft_lstnew.c		ft_lstdelone.c \
			  ft_lstdel.c		ft_lstadd.c		ft_lstiter.c \
			  ft_lstmap.c		ft_isspace.c	ft_str_is_uppercase.c \
			  ft_islower.c		ft_isupper.c	ft_str_is_lowercase.c \
			  ft_lstpushback.c	ft_strupcase.c	ft_str_is_alpha.c \
			  ft_strlowcase.c	ft_tabiter_int.c ft_print_tab_int.c \
			  ft_strcapitalize.c ft_itoa_base.c	ft_strndup.c \
			  ft_sqrt.c

OBJ	= $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@echo -n 'Compiling	$(NAME)		-->	'
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GRN)'Done !'$(RESET)

%.o:		%.c
	@$(CC) $(CFLAGS) -c $? -o $@

clean:
	@echo -n 'Removing	objects		-->	'
	@$(RM) $(OBJ)
	@echo $(GRN)'Done !'$(RESET)

fclean:		clean
	@echo -n 'Removing	$(NAME)		-->	'
	@$(RM) $(NAME)
	@echo $(GRN)'Done !'$(RESET)

re:			fclean all
