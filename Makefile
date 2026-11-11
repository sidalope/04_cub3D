# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abisiani <abisani@student.42berlin.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/11 11:28:24 by abisiani          #+#    #+#              #
#    Updated: 2026/11/11 12:53:23 by abisiani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean valgrind re

CC 			= cc
CFLAGS 		= -g -Wall -Werror -Wextra
LDFLAGS 	= -Lminilibx-linux
LDLIBS 		= -lmlx -lXext -lX11 -lm

NAME 		= cub3D
LIBFT 		= libft/libft.a
MINILIBX 	= minilibx-linux/libmlx.a

SRC_DIR 	= src
TEST_DIR 	= tests
OBJ_DIR 	= obj

MAIN_FILES 	= cub3d.c
SRC_FILES 	= 
TEST_FILES 	= test.c

MAIN 		= $(addprefix $(SRC_DIR)/, $(MAIN_FILES))
SRC 		= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
TEST 		= $(addprefix $(TEST_DIR)/, $(TEST_FILES))

MAIN_OBJ 	= $(addprefix $(OBJ_DIR)/, $(MAIN:.c=.o))
SRC_OBJ 	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
TEST_OBJ 	= $(addprefix $(OBJ_DIR)/, $(TEST:.c=.o))

INCLUDES	= -I ./includes/\
				-I ./libft/\
				-I ./minilibx-linux/

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(MINILIBX):
	$(MAKE) -C minilibx-linux

$(NAME): $(MAIN_OBJ) $(SRC_OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(TEST_NAME): $(TEST_OBJ) $(SRC_OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) $(LDLIBS) -o $(TEST_NAME)

$(OBJ_DIR)/%.o: %.c includes/cub3d.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C libft clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
# 	rm -f $(NAME) $(TEST_NAME)

# test: $(NAME)
# 	@bash tests/run_tests.sh

valgrind: $(NAME)
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--trace-children=yes \
	--track-fds=yes \
	--suppressions=readline.supp \
	./$(NAME)

re: fclean all