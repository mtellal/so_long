# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtellal <mtellal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 16:51:29 by mtellal           #+#    #+#              #
#    Updated: 2022/01/06 16:08:16 by mtellal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CLAGS = -Wextra -Wall -Werror

NAME = so_long

SRC = parse/check_things.c parse/parse_map.c parse/check_things_utils.c \
	src/utils.c src/pixels.c src/game.c src/events.c src/window.c src/elements.c src/move.c main.c

HEADER = -I includes -I libft -I mlx 

LIBFT = -L libft/ -lft

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME):
	make -C libft/
	make -C mlx/	
	$(CC) -g  -o $(NAME) $(HEADER) $(SRC) -L mlx/  $(LIBFT) -lmlx -lXext -lX11 

r: re 
	./$(NAME)  maps/map.ber 

val: re
	valgrind --leak-check=full --tool=memcheck \
	--show-reachable=yes --track-fds=yes \
	--errors-for-leak-kinds=all --show-leak-kinds=all ./$(NAME) maps/map.ber 

clean:
	make clean -C libft
	make clean -C mlx	
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all
