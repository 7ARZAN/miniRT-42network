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

ifeq ($(OS), Linux)
	MLX_FLAGS = -lmlx42 -ldl -lglfw -pthread -lm
else
	MLX_FLAGS = -framework Cocoa -framework OpenGL -framework IOKit
	LIB_DIR = /Users/$(USER)/Library/lib/libmlx42.a
	GLFW_DIR = /Users/$(USER)/Library/lib/libglfw3.a
	INC_DIR = -I/Users/$(USER)/Library/includes/
endif

SRC = main.c \
      parsing/basic_check.c parsing/parser.c parsing/ps_elmnts.c parsing/ps_objects.c \
      raytracing/raytracing.c raytracing/raytracing_utils.c \
      render/render.c vectors/vctr.c vectors/vec.c \
      lib/allocation.c lib/gb_collector.c lib/gnl.c lib/ohmysplit.c lib/utils.c

OBJ = $(SRC:%.c=build/%.o)

INCLUDES = include/minirt.h include/structs.h

build/%.o: %.c $(INCLUDES)
	@mkdir -p $(dir $@)
	$(CC) $(INC_DIR) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_DIR) $(GLFW_DIR) $(MLX_FLAGS) $(INC_DIR) -o $(NAME)

clean:
	rm -rf build/
	rm -rf miniRT.dSYM

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
