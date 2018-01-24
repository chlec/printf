# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clecalie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 15:12:41 by clecalie          #+#    #+#              #
#    Updated: 2018/01/24 10:51:29 by clecalie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
		apply_flag.c \
		ft_printf.util.c \
		handle_flags.c \
		handle_letters_dxou.c \
		handle_letters_sc.c \
		manipulation.c \
		precision.c \
		wchartoasc.c \
		manip_sc_up.c \
		replacestr.c \
		ft_atol.c \
		ft_uintmaxtoa.c \
		ft_intmaxtoa.c \
		ft_uintmaxtoa_base.c \
		ft_intmaxtoa_base.c \
		ft_ulltoa.c \
		ft_ulltoa_base.c \
		handle_sharp.c \
		handle_neg.c \
		handle_plus.c \
		handle_digit.c \
		handle_space.c \
		handle_zero.c

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
			libft/ft_strnequ.o \
			libft/ft_strlen.o \
			libft/ft_strncmp.o \
			libft/ft_strndup.o \
			libft/ft_strnew.o \
			libft/ft_strrev.o \
			libft/ft_strstr.o \
			libft/ft_strsub.o \
			libft/ft_strtolower.o \
			libft/ft_toupper.o \
			libft/ft_bzero.o \
			libft/ft_strdel.o \
			libft/ft_isprint.o

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
