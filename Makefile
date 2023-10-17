# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 19:52:52 by elakhfif          #+#    #+#              #
#    Updated: 2023/10/17 22:27:28 by elakhfif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
CC = cc
NAME = miniRT
GNL_SRC = lib/gnl/gnl.c
OBJ = #build/ all dot.o
SRC = #all my dot.c
INCLUDES = include/minirt.h

build/%.o : src/%.c // #i should change src with my folders !
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
