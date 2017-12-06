# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clecalie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:12:41 by clecalie          #+#    #+#              #
#    Updated: 2017/12/06 15:29:22 by clecalie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	main.c \
		handle_flags.c \
		manipulation.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	#gcc $(OBJ) libft/libft.a -o test
	ar rc $(NAME) $(OBJ) libft/libft.a libft/*.o

%.o: %.c
	gcc -c $< -Werror -Wextra -Wall -I libft/includes

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
