# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 08:55:09 by kyanagis          #+#    #+#              #
#    Updated: 2025/08/09 05:25:43 by kyanagis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    := push_swap

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -Iinclude -Ilibft/include
LDFLAGS := -Llibft -lft        


SRCS := \
src/push_swap.c \
src/parse.c \
src/ft_split_ws.c \
src/utils/node_utils.c \
src/utils/free_utils.c\
src/order/swap.c \
src/order/push.c \
src/order/rotate.c \
src/order/reverse_rotate.c \
src/sort_five_ida/ida_dfs.c \
src/sort_five_ida/ida_ops.c \
src/sort_five_ida/ida_utils.c \
src/sort_five_ida/ida_star.c \
src/sort_five_ida/sort_five.c \
src/sort_medium/test.c \
# src/LIS.c \
# src/sort_medium/sort_medium.c
OBJS := $(SRCS:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJS) libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

libft/libft.a:
	$(MAKE) -C libft


clean:
	$(MAKE) -C libft clean
	rm -rf obj

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
