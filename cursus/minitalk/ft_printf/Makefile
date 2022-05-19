# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 04:42:07 by ylakhoua          #+#    #+#              #
#    Updated: 2021/12/09 13:24:48 by ylakhoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_printf_funcs.c
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	gcc $(CFLAGS) -c $<

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
