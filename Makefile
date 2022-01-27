# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 17:10:46 by danisanc          #+#    #+#              #
#    Updated: 2022/01/27 20:00:07 by danisanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = address.c decimal.c ft_putstr.c  string.c hex.c printu.c ft_printf.c

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Werror -Wextra -Wall

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re