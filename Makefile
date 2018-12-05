# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 09:14:19 by dtrigalo          #+#    #+#              #
#    Updated: 2018/12/05 18:11:09 by anleclab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra
SRCS = accufield_functions.c \
	   conv_big_x.c \
	   conv_c.c \
	   conv_d.c \
	   conv_i.c \
	   conv_o.c \
	   conv_p.c \
	   conv_percentage.c \
	   conv_s.c \
	   conv_u.c \
	   conv_x.c \
	   flag_functions.c \
	   ft_printf.c \
	   parse_accufield.c \
	   parse_conv.c \
	   parse_flag.c \
	   conv_f.c \
	   exit_error.c
OBJ = $(SRCS:.c=.o)
HEADERS = ft_printf.h

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
