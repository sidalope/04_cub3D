# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abisiani <abisani@student.42berlin.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/11 11:28:24 by abisiani          #+#    #+#              #
#    Updated: 2026/11/13 10:28:39 by abisiani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re test valgrind FORCE

CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra
LDFLAGS 	= -L$(MLX_DIR)
LDLIBS 		= -lmlx -lXext -lX11 -lm

NAME 		= cub3D
TEST_NAME 	= test_cub3D
TEST_MAP	= maps/valid/library.cub

LIBS_DIR 	= libs
LIBFT_DIR 	= $(LIBS_DIR)/libft
LIBFT 		= $(LIBFT_DIR)/libft.a
MLX_DIR 	= $(LIBS_DIR)/minilibx-linux
MINILIBX 	= $(MLX_DIR)/libmlx.a

SRC_DIR 	= src
TEST_DIR 	= tests
OBJ_DIR 	= obj

MAIN_FILES 	= cub3d.c
ERROR_FILES	= error.c
UTILS_FILES	= clean_up.c
INIT_FILES	= init.c
TEST_FILES 	= test.c

MAIN 		= $(addprefix $(SRC_DIR)/, $(MAIN_FILES))
SRC 		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))\
				$(addprefix $(SRC_DIR)/error/, $(ERROR_FILES))\
				$(addprefix $(SRC_DIR)/utils/, $(UTILS_FILES))\
				$(addprefix $(SRC_DIR)/init/, $(INIT_FILES))
TEST 		= $(addprefix $(TEST_DIR)/, $(TEST_FILES))

MAIN_OBJ 	= $(addprefix $(OBJ_DIR)/, $(MAIN:.c=.o))
SRC_OBJ 	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
TEST_OBJ 	= $(addprefix $(OBJ_DIR)/, $(TEST:.c=.o))

INCLUDES	= -I ./includes/\
				-I ./$(LIBFT_DIR)/src/\
				-I ./$(MLX_DIR)/

all: $(NAME)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(MAIN_OBJ) $(SRC_OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(TEST_NAME): $(TEST_OBJ) $(SRC_OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $(TEST_NAME)

$(OBJ_DIR)/%.o: %.c includes/cub3d.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(TEST_NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

test: $(TEST_NAME)
	./$(TEST_NAME)

valgrind: $(NAME)
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-fds=yes \
	./$(NAME) $(TEST_MAP)

FORCE:

re: fclean all