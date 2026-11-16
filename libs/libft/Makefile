# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abisiani <abisani@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 15:15:30 by abisiani          #+#    #+#              #
#    Updated: 2026/11/16 20:04:00 by abisiani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re test

CC = cc
CFLAGS = -I. -Wall -Werror -Wextra
AR = ar rcs

NAME = libft.a
TEST_EXEC = test

OBJ_DIR = obj
SRC_DIR = src

TEST_FILES = tests.c
SRC_FILES = ft_isalpha.c ft_toupper.c ft_tolower.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_atoi.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c  ft_calloc.c \
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putunbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c ft_intlen.c
GNL_FILES = get_next_line.c get_next_line_utils.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))\
		$(addprefix $(SRC_DIR)/get_next_line/, $(GNL_FILES))

OBJ=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_EXEC)

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) -o $(TEST_EXEC) tests/tests.c -L. -lft -lbsd
	./$(TEST_EXEC)
