# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abisiani <abisani@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/11 11:28:24 by abisiani          #+#    #+#              #
#    Updated: 2026/11/16 19:31:20 by abisiani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re test test_all test_valgrind valgrind FORCE

CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra
LDFLAGS 	= -L$(MLX_DIR)
LDLIBS 		= -lmlx -lXext -lX11 -lm

NAME 			= cub3D
TEST_MAP		= tests/maps/valid/library.cub

LIBS_DIR 	= libs
LIBFT_DIR 	= $(LIBS_DIR)/libft
LIBFT 		= $(LIBFT_DIR)/libft.a
MLX_DIR 	= $(LIBS_DIR)/minilibx-linux
MINILIBX 	= $(MLX_DIR)/libmlx.a

SRC_DIR 	= src
TEST_DIR 	= tests
OBJ_DIR 	= obj

MAIN_FILES		= cub3d.c
ERROR_FILES		= error.c
UTILS_FILES		= clean_up.c ft_atoi_cub3d.c is_whitespace.c skip_whitespace.c \
					strip_newline.c
INIT_FILES		= init.c init_mlx.c
PARSING_FILES	= parse_cub.c parse_configs.c parse_colours.c parse_map.c
TEST_FILES		= test.c

RENDER_FILES	= stub_config.c screen.c draw.c hooks.c

MAIN 		= $(addprefix $(SRC_DIR)/, $(MAIN_FILES))
SRC 		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))\
				$(addprefix $(SRC_DIR)/error/, $(ERROR_FILES))\
				$(addprefix $(SRC_DIR)/utils/, $(UTILS_FILES))\
				$(addprefix $(SRC_DIR)/init/, $(INIT_FILES))\
				$(addprefix $(SRC_DIR)/init/parsing/, $(PARSING_FILES))\
				$(addprefix $(SRC_DIR)/render/, $(RENDER_FILES))
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

test_all: $(NAME)
	./tests/test_all.sh

test_valgrind: $(NAME)
	./tests/test_valgrind.sh

test: $(NAME)
	$(info )
	$(info Running with TEST_MAP pointing to: $(TEST_MAP))
	$(info To change map:)
	$(info )
	$(info MAP=tests/maps/valid/cheese_maze.cub)
	$(info make test TEST_MAP=$$MAP)
	$(info )
	./$(NAME) $(TEST_MAP)

valgrind: $(NAME)
	$(info Running with TEST_MAP pointing to: $(TEST_MAP))
	$(info To change map:)
	$(info )
	$(info MAP=tests/maps/valid/cheese_maze.cub)
	$(info make valgrind TEST_MAP=$$MAP)
	$(info )
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-fds=yes \
		--errors-for-leak-kinds=all \
		--log-file="tests/output/single_valgrind.txt" \
		./cub3D $(TEST_MAP)

FORCE:

re: fclean all