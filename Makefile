# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 17:10:46 by danisanc          #+#    #+#              #
#    Updated: 2022/01/12 17:31:18 by danisanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

CC= gcc

CFLAGS= -Wall -Wextra -Werror -I.

SRCS= address.c ft_printf.c decimal.c hex.c printu.c string.c

OBJS= $(SRCS:.c=.o)


$(NAME): $(OBJS)
	ar rcs $@ $^
	 
bonus: $(OBJS) $(OBJSPLUS)
	ar rcs $(NAME) $^

all: $(NAME)

.PHONY : clean
clean:
	rm $(OBJS) $(OBJSPLUS)

fclean: clean
	rm $(NAME)

re: fclean all