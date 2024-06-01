# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iziane <iziane@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 21:12:03 by iziane            #+#    #+#              #
#    Updated: 2024/06/02 00:28:01 by iziane           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME			=	fractol
HEADER			=	-I ./include -I $(LIBMLX)/include

MLXFLAGS		=	-framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/iziane/.brew/Cellar/cmake/"

MLX_PATH		=	./MLX42/build
MLX				=	$(MLX_PATH)/libmlx42.a
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Wunreachable-code -Ofast -g

SRC			=	$(addprefix src/, main.c input_check.c hooks.c error_case.c)
OBJ			=	$(SRC:%.c=%.o)

INCL		=	-I./MLX42/include/MLX42/ -I./libft/ -I./includes/

all: MLX42
	$(MAKE) $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(INCL) $(MLXFLAGS)  $(OBJ) $(LIBS)  $(LIBFT) -o $(NAME) $(MLX)

MLX42:
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@cd MLX42 && cmake -B build && cmake --build build -j4

%.o : %.c
	$(CC) $(INCL) $(LIBS) $(CFLAGS) $(HEADER) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH)

fclean: clean
	-make fclean -C $(LIBFT_PATH)
	@rm -rf $(NAME)

clean:
	-make clean -C $(LIBFT_PATH)
	# -make clean -C $(MLX_PATH)
	# @rm -rf MLX42
	@rm -rf $(OBJ)

re: fclean all

.PHONY: all fclean clean re


#MAkefile works but error
# .SILENT:

# NAME			=	fractol
# HEADER			=	fractol.h -I ./include -I $(LIBMLX)/include

# MLXFLAGS		=	-framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

# MLX_PATH		=	./MLX42/build
# MLX				=	$(MLX_PATH)/libmlx42.a
# LIBFT_PATH		=	./libft
# LIBFT			=	$(LIBFT_PATH)/libft.a

# CC				=	cc
# CFLAGS			=	-Wall -Wextra -Werror -Wunreachable-code -Ofast -g

# SRC				=	src/fractol_init.c\
# 					main.c
# OBJ				=	$(SRC:%.c=%.o)

# all: MLX42 $(LIBFT) $(MLX) $(NAME)

# $(NAME): MLX42 $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(MLXFLAGS)

# MLX42:
# 	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
# 	@cd MLX42 && cmake -B build && cmake --build build -j4

# %.o : %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(LIBFT):
# 	make -C $(LIBFT_PATH)

# $(MLX):
# 	make -C $(MLX_PATH)

# fclean: clean
# 	make fclean -C $(LIBFT_PATH)
# 	if [ -d "$(MLX_PATH)" ]; then make clean -C $(MLX_PATH); fi
# 	@rm -rf $(NAME)

# clean:
# 	make clean -C $(LIBFT_PATH)
# 	if [ -d "$(MLX_PATH)" ]; then make clean -C $(MLX_PATH); fi
# 	@rm -rf MLX42
# 	@rm -rf $(OBJ)
# 	@rm -rf $(OBJ_MAIN)

# re: fclean all

# .PHONY: all fclean clean re


# NAME			=	fractol
# HEADER			=	fractol.h -I ./include -I $(LIBMLX)/include

# MLXFLAGS		=	-framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

# MLX_PATH		=	./MLX42/build
# MLX				=	$(MLX_PATH)/libmlx42.a
# LIBFT_PATH		=	./libft
# LIBFT			=	$(LIBFT_PATH)/libft.a

# CC				=	cc
# CFLAGS			=	-Wall -Wextra -Werror -Wunreachable-code -Ofast -g

# SRC				=	fractol_init.c main.c
# OBJ				=	$(SRC:%.c=%.o)

# all: MLX42 $(LIBFT) $(NAME)

# $(NAME): $(OBJ)
# 	@echo "Linking $(NAME)..."
# 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(MLXFLAGS)

# MLX42:
# 	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
# 	@cd MLX42 && cmake -B build && cmake --build build -j4

# %.o: %.c
# 	@echo "Compiling $<..."
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(LIBFT):
# 	@echo "Building libft..."
# 	make -C $(LIBFT_PATH)

# $(MLX):
# 	@echo "Building MLX42..."
# 	make -C $(MLX_PATH)

# fclean: clean
# 	@echo "Cleaning all..."
# 	make fclean -C $(LIBFT_PATH)
# 	if [ -d "$(MLX_PATH)" ]; then make clean -C $(MLX_PATH); fi
# 	@rm -rf $(NAME)

# clean:
# 	@echo "Cleaning objects..."
# 	make clean -C $(LIBFT_PATH)
# 	if [ -d "$(MLX_PATH)" ]; then make clean -C $(MLX_PATH); fi
# 	@rm -rf $(OBJ)

# re: fclean all

# .PHONY: all fclean clean re MLX42




# .SILENT:

# NAME			=	fractol

# MLXFLAGS		=	-framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
# LIBFT_PATH		=	./libft
# LIBFT			=	$(LIBFT_PATH)/libft.a

# CC			=	cc
# CFLAGS		=	-Wall -Wextra -Werror -g

# SRC			=	main.c \
# 				$(addprefix parser/, input_check.c substring_cases.c utils.c arrayz.c)\
# 				$(addprefix list_list/, error.c list.c operation_pa.c operation_pb.c operation_sa.c operation_sb.c operation_ss.c operation_ra_or_rb.c operation_rr.c operation_rra_or_rrb.c operation_rrr.c list_manipulator.c utils_algo.c algo.c post_sort.c utils_algo_2.c move_maker.c pre_sort.c go2algo.c)\

# OBJ			=	$(SRC:%.c=%.o)

# MLX42:
# 	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
# 	@cd MLX42 && cmake -B build && cmake --build build -j4

# all: MLX42 $(NAME)

# $(NAME): $(LIBFT) $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) $(MLXFLAGS)

# %.o : %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# $(LIBFT):
# 	make -C $(LIBFT_PATH)

# fclean: clean
# 	make fclean -C $(LIBFT_PATH)
# 	@rm -rf $(NAME)

# clean:
# 	make clean -C $(LIBFT_PATH)
# 	@rm -rf $(OBJ)
# 	@rm -rf MLX

# re: fclean all

# .PHONY: all fclean clean re
