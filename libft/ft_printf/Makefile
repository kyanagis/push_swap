# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/21 15:19:07 by kyanagis          #+#    #+#              #
#    Updated: 2025/07/05 04:28:23 by kyanagis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        := libftprintf.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -I. -I../libft

SRC_DIR     := .
OBJ_DIR     := obj

SRC         := $(SRC_DIR)/ft_printf.c \
               $(SRC_DIR)/ft_format.c \
               $(SRC_DIR)/ft_utils.c

OBJ         := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

LIBFT_DIR   := ../libft
LIBFT       := $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re $(LIBFT)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
