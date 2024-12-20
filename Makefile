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

CFLAGS = -Wall -Wextra -Werror -Wformat=2 -flto -ffast-math -pedantic -Wunreachable-code -Wfloat-equal -Warray-bounds -ggdb -O3 -ffast=math 

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

GNL_SRC = lib/gnl.c

OBJ = $(SRC:src/%.c=build/%.o)

SRC = parsing/basic_check.c parsing/parser.c parsing/ps_elmnts.c parsing/ps_objects.c \
      raytracing/raytracing.c raytracing/raytracing_utils.c \
      render/render.c vectors/vec.c vectors/vctr.c main.c\

INCLUDES = include/minirt.h

build/%.o : src/%.c $(INCLUDES)
	$(CC) $(INC_DIR) $< $(CFLAGS) -c -o $@

all : build $(NAME)

build :
	if [ -d "build/" ]; then \
	    echo "[*] - Build folder does exist"; \
	else \
		mkdir build; \
	fi

$(NAME) : $(OBJ) $(GNL_SRC) $(INCLUDES)
	$(CC) $(CFLAGS) $(LIB_DIR) $(OBJ) $(GLFW_DIR) $(MLX_FLAGS) $(INC_DIR) $(GNL_SRC) -o $(NAME)

clean :
	rm -rf build/
	rm -rf miniRT.dSYM

fclean : clean
	rm -rf $(NAME)

re : fclean all
