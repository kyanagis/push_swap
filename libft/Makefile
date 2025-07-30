# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/15 10:40:00 by kyanagis          #+#    #+#             #
#    Updated: 2025/07/15 10:40:00 by kyanagis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME      := libft.a
CC        := cc
CFLAGS    := -Wall -Wextra -Werror -Iinclude -Ift_printf
AR        := ar
ARFLAGS   := rcs
RM        := rm -f


SRC_PRINTF := \
	ft_printf/ft_format.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_utils.c


SRC_CHAR := \
	src/char/ft_isalnum.c \
	src/char/ft_isalpha.c \
	src/char/ft_isascii.c \
	src/char/ft_isdigit.c \
	src/char/ft_isprint.c \
	src/char/ft_isspace.c


SRC_CONVERT := \
	src/convert/ft_atof.c \
	src/convert/ft_atoi.c \
	src/convert/ft_atol.c


SRC_IO := \
	src/IO/ft_putchar_fd.c \
	src/IO/ft_putendl_fd.c \
	src/IO/ft_putnbr_fd.c \
	src/IO/ft_putstr_fd.c


SRC_LIST := \
	src/list/ft_lstadd_back.c \
	src/list/ft_lstadd_front.c \
	src/list/ft_lstclear.c \
	src/list/ft_lstdelone.c \
	src/list/ft_lstiter.c \
	src/list/ft_lstlast.c \
	src/list/ft_lstmap.c \
	src/list/ft_lstnew.c \
	src/list/ft_lstsize.c


SRC_MEMORY := \
	src/memory/ft_bzero.c \
	src/memory/ft_calloc.c \
	src/memory/ft_memchr.c \
	src/memory/ft_memcmp.c \
	src/memory/ft_memcpy.c \
	src/memory/ft_memmove.c \
	src/memory/ft_memset.c


SRC_STRING := \
	src/string/ft_split.c \
	src/string/ft_strdup.c \
	src/string/ft_strjoin.c \
	src/string/ft_strlcpy.c \
	src/string/ft_strmapi.c \
	src/string/ft_strnstr.c \
	src/string/ft_strtrim.c \
	src/string/ft_strchr.c \
	src/string/ft_striteri.c \
	src/string/ft_strlcat.c \
	src/string/ft_strlen.c \
	src/string/ft_strncmp.c \
	src/string/ft_strrchr.c \
	src/string/ft_substr.c


SRC_FREE := \
	src/free/free_split.c

SRC_UTILS := \
	src/utils/error_exit.c

SRC := $(SRC_PRINTF) $(SRC_CHAR) $(SRC_CONVERT) $(SRC_IO) \
       $(SRC_LIST) $(SRC_MEMORY) $(SRC_STRING) $(SRC_FREE) \
	   $(SRC_UTILS)

OBJ := $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $(OBJ)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
