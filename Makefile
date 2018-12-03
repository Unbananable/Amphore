# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtrigalo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 09:14:19 by dtrigalo          #+#    #+#              #
#    Updated: 2018/12/03 17:20:47 by anleclab         ###   ########.fr        #
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
	   parse_flag.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(FLAGS) $(OBJ) -o $(NAME) -Llibft -lft -I$(HEADERS)
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
