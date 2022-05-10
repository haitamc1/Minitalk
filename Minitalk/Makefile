# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hchahid <hchahid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 03:46:37 by hchahid           #+#    #+#              #
#    Updated: 2022/03/16 18:21:03 by hchahid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


HEADER = minitak.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
SSRC = server.c utils.c
CSRC = client.c utils.c
SOBJ = $(SSRC:.c=.o)
COBJ = $(CSRC:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: server client
	

server: $(SOBJ)
	$(CC) $(SOBJ) -o server

client: $(COBJ)
	$(CC) $(COBJ) -o client
	

clean:
	rm -rf $(COBJ) $(SOBJ)

fclean: clean
	rm -rf client
	rm -rf server

re: fclean all

.PHONY: clean fclean all re
