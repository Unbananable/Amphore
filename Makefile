# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 09:14:19 by dtrigalo          #+#    #+#              #
#    Updated: 2018/12/06 11:23:22 by anleclab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c					\
	   parse_conv.c					\
	   conv_functions_char.c		\
	   conv_functions_int.c			\
	   conv_functions_double.c		\
	   conv_functions_percentage.c	\
	   parse_accufield.c			\
	   accufield_functions.c		\
	   parse_flag.c					\
	   flag_functions.c				\
	   exit_error.c
OBJ = $(SRCS:.c=.o)
HEADERS = ft_printf.h libft/libft.h

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	make -C ./libft
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
