# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 19:52:52 by elakhfif          #+#    #+#              #
#    Updated: 2023/10/17 21:05:01 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

INC = -I./include

CC = cc

CFLAGS = -Wall -Wextra -Werror -O3 -ffast-math

MLX = -L./minilibx -lmlx -framework OpenGL -framework AppKit

SRC =

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./minilibx
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(MLX) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean -C ./minilibx
	@rm -rf $(OBJ)

fclean: clean
	@make clean -C ./minilibx
	@rm -rf $(NAME)

re: fclean all
