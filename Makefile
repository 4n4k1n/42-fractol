# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 20:58:57 by anakin            #+#    #+#              #
#    Updated: 2025/04/26 14:32:21 by apregitz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fractol
CFLAGS	:= -Wall -Wextra -Werror -Wunreachable-code -Ofast -march=native -mtune=native -flto -funroll-loops
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRC_DIR = src
OBJ_DIR = obj

SRCS	:= calc.c \
			change_fractol.c \
			color.c \
			color_flow_rainbow.c \
			color_flow_round.c \
			ft_atof.c \
			ft_strcmp.c \
			func_ptr.c \
			init_burningship.c \
			init_julia.c \
			init_mandelbrot.c \
			init_rgb.c \
			init_static_function.c \
			init_zoom.c \
			key_hook.c \
			main.c \
			mouse_hook.c \
			parsing.c \
			print_fractol.c \
			resize_hook.c \
			zoom.c \
			recreate_img.c

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re libmlx