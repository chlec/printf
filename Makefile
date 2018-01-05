# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clecalie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:12:41 by clecalie          #+#    #+#              #
#    Updated: 2018/01/05 13:11:43 by clecalie         ###   ########.fr        #
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
		manip_sc_up.c

OBJ = $(SRCS:.c=.o)

LIB_OBJ =	libft/ft_atoi.o \
			libft/ft_ctos.o \
			libft/ft_isdigit.o \
			libft/ft_itoa.o \
			libft/ft_itoa_base.o \
			libft/ft_putchar.o \
			libft/ft_putstr.o \
			libft/ft_strcat.o \
			libft/ft_strchr.o \
			libft/ft_strcmp.o \
			libft/ft_strdup.o \
			libft/ft_strequ.o \
			libft/ft_strlen.o \
			libft/ft_strncmp.o \
			libft/ft_strndup.o \
			libft/ft_strnew.o \
			libft/ft_strrev.o \
			libft/ft_strstr.o \
			libft/ft_strsub.o \
			libft/ft_strtolower.o \
			libft/ft_toupper.o \
			libft/ft_bzero.o

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	ar rc $(NAME) $(OBJ) libft/libft.a $(LIB_OBJ)

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
