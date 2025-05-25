# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 19:52:52 by elakhfif          #+#    #+#              #
#    Updated: 2024/12/20 23:24:50 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

CC = cc

CFLAGS = -Wall -Wextra -Werror -Wformat=2 -flto -ffast-math -pedantic -O3

OS := $(shell uname -s)

USER := $(shell whoami)

INC_DIR = -I./include -I./include/MLX42

ifeq ($(OS), Linux)
	MLX_FLAGS = -L./lib/MLX42/build -lmlx42 -ldl -lglfw -pthread -lm
else
	MLX_FLAGS = -L./42/MLX42/build -lmlx42 -L/Users/elakhfif/.brew/opt/glfw/lib -lglfw -framework OpenGL -framework AppKit
	LIB_DIR = ./42/MLX42/build/libmlx42.a
endif

SRC = main.c \
      parsing/basic_check.c parsing/parser.c parsing/ps_elmnts.c parsing/ps_objects.c \
      raytracing/raytracing.c raytracing/raytracing_utils.c \
      render/render.c vectors/vctr.c vectors/vec.c \
      lib/allocation.c lib/gb_collector.c lib/gnl.c lib/ohmysplit.c lib/utils.c

OBJ = $(SRC:%.c=build/%.o)

INCLUDES = include/minirt.h include/structs.h

$(LIB_DIR):
	@echo "Building MLX42..."
	@cd 42/MLX42 && cmake -B build && cmake --build build -j4

build/%.o: %.c $(INCLUDES) | $(LIB_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_DIR) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf build/
	rm -rf miniRT.dSYM

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
