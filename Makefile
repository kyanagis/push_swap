# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/30 02:20:06 by kyanagis          #+#    #+#              #
#    Updated: 2025/07/30 02:20:48 by kyanagis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := push_swap


SRC_DIR     := src
OBJ_DIR     := obj
INC_DIR     := include
LIBFT_DIR   := libft
LIBFT_A     := $(LIBFT_DIR)/libft.a



SRC_FILES   := push_swap.c parse.c node_utils.c
SRC         := $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJ         := $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))


CC          := cc
CFLAGS      := -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/include
LDFLAGS     := -L$(LIBFT_DIR) -lft




all: $(NAME)


$(NAME): $(LIBFT_A) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)


clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
