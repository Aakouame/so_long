# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akouame <akouame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 21:02:23 by akouame           #+#    #+#              #
#    Updated: 2022/08/10 12:57:50 by akouame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS = so_long.c\

OBJS = $(SRCS:.c=.o)
HEADER = so_long.h

all: $(NAME)

%.o:%.c HEADER
	$(CC) $(OBJS) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all re clean fclean