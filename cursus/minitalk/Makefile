# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylakhoua <ylakhoua@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 21:10:13 by ylakhoua          #+#    #+#              #
#    Updated: 2022/04/29 21:10:14 by ylakhoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: server client server_bonus client_bonus
Mall: server client
Ball: server_bonus client_bonus

server: ft_printf/libftprintf.a
	cc -Wall -Wextra -Werror server.c ft_printf/libftprintf.a -o server

client:
	cc -Wall -Wextra -Werror client.c -o client

clean:
	make clean -C ft_printf
	rm -f server client

bonus_clean:
	rm -f server_bonus client_bonus

server_bonus: ft_printf/libftprintf.a
	cc -Wall -Wextra -Werror server_bonus.c ft_printf/libftprintf.a -o server_bonus

client_bonus:
	cc -Wall -Wextra -Werror client_bonus.c -o client_bonus

ft_printf/libftprintf.a:
	make -C ft_printf

fclean: clean bonus_clean
	make fclean -C ft_printf

re: fclean all
