test_d: 
	@make -C ./libft
	@make -C ./libft clean
	@gcc -Wall -Wextra -Llibft -lft maintest.c printf_d.c flag_functions.c \
		accufield_functions.c parse_accufield.c parse_flag.c -o test_d

clean:
	@rm test_d

re: clean test_d

.PHONY: clean re
