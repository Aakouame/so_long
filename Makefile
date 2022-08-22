# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akouame <akouame@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 21:02:23 by akouame           #+#    #+#              #
#    Updated: 2022/08/22 10:56:46 by akouame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS = so_long.c\
		./get_next_line/get_next_line.c\
		./get_next_line/get_next_line_utils.c\
		check.c\
		help_check.c\
		build.c\
		play.c\
		help_play.c\
		
OBJS = $(SRCS:.c=.o)

HEADER = so_long.h
LIBFT = ./libft/libft.a
PATH_LIBFT = ./libft

all: $(NAME)

$(LIBFT): ${PATH_LIBFT}
	make -C ${PATH_LIBFT}

# %.o:%.c HEADER
	# $(CC) $(OBJS) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(HEADER)
	$(CC) $(OBJS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)
	make clean -C ${PATH_LIBFT}
fclean: clean
	rm -rf $(NAME)
	make fclean -C ${PATH_LIBFT}
re: fclean all

.PHONY: all re clean fclean