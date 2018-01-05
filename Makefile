# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clecalie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:12:41 by clecalie          #+#    #+#              #
#    Updated: 2018/01/05 10:09:35 by clecalie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	main.c \
		handle_flags.c \
		manipulation.c \
		flag_format.c \
		precision.c \
		ft_wputstr.c \
		ft_atol.c \
		ft_uintmaxtoa.c \
		ft_intmaxtoa.c \
		ft_uintmaxtoa_base.c \
		ft_intmaxtoa_base.c \
		ft_ulltoa.c \
		ft_ulltoa_base.c \
		manip_SC.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	#gcc $(OBJ) libft/libft.a -o test
	ar rc $(NAME) $(OBJ) libft/libft.a libft/*.o

%.o: %.c
	gcc -c $< $(FLAGS) -I libft/includes

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
