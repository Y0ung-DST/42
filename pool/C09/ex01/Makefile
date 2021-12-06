# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/15 20:15:59 by ylakhoua          #+#    #+#              #
#    Updated: 2021/07/15 21:20:21 by ylakhoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS = ${SRCS:.c=.o}

.c.o:

gcc -Wall -Wextra -Werror -I includes -c $< -o ${<:.c=.o}

libft.a: ${OBJS}

ar rcs libft.a ${OBJS}

all: libft.a

clean:

rm -f {OBJS}

fclean: clean

rm -f libft.a

re: fclean all
