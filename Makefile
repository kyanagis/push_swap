NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
INCS := -Iinclude -Ilibft/include -Ilibft/ft_printf

LIBFT_DIR := libft
LIBFT_A := $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR := $(LIBFT_DIR)/ft_printf
FT_PRINTF_A := $(FT_PRINTF_DIR)/libftprintf.a

VPATH := src:src/order:src/sort_three:src/sort_five_ida:src/sort_large:src/utils

SRCS := \
push_swap.c \
parse.c \
LIS.c \
push.c \
swap.c \
rotate.c \
reverse_rotate.c \
sort_three.c \
ida_dfs.c \
ida_ops.c \
ida_star.c \
ida_utils.c \
sort_five.c \
compute_best_from_b.c \
coord_compress.c \
insert_cost.c \
insert_utils.c \
large_core_utils.c \
large_rotate.c \
lis_seed.c \
push_nonlis.c \
sort_large.c \
free_utils.c \
ft_split_ws.c \
node_utils.c \
zero_keep.c

OBJDIR := build
OBJS := $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
DEPS := $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(LIBFT_A) $(FT_PRINTF_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(FT_PRINTF_A) -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_A):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	-$(MAKE) -C $(LIBFT_DIR) clean
	-$(MAKE) -C $(FT_PRINTF_DIR) clean
	@rm -rf $(OBJDIR)

fclean: clean
	-$(MAKE) -C $(LIBFT_DIR) fclean
	-$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
-include $(DEPS)
