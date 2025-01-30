# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: motelti <motelti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/21 23:22:33 by motelti           #+#    #+#              #
#    Updated: 2025/01/28 11:17:11 by motelti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
RM		= @rm -f
CLEAR	= @clear

# File Names
NAME	= push_swap
BONUS_NAME = checker
HEADER = push_swap.h

SRC		= swap_push/main.c \
          swap_push/check_free.c \
          swap_push/helpers.c \
          swap_push/push.c \
          swap_push/reverse.c \
          swap_push/rotate.c \
          swap_push/swap.c \
          swap_push/index.c \
          swap_push/sorte_3_4_5.c \
          swap_push/sort_utils.c \
		  swap_push/chunks_sort.c \
		  swap_push/chunk_utilis.c \
		  swap_push/sort_3.c \
          $(addprefix ./libft/, $(LIBFT_SRC)) \
          $(addprefix ./ft_printf/, $(PRINTF_SRC))

BONUS_SRC = bonus/checker.c \
            bonus/get_next_line/get_next_line.c \
            bonus/get_next_line/get_next_line_utils.c \
            swap_push/check_free.c \
            swap_push/helpers.c \
            swap_push/push.c \
            swap_push/reverse.c \
            swap_push/rotate.c \
            swap_push/swap.c \
            swap_push/index.c \
            swap_push/sort_utils.c \
            $(addprefix ./libft/, $(LIBFT_SRC)) \
            $(addprefix ./ft_printf/, $(PRINTF_SRC))

OBJ		= $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)


# External Libraries
LIBFT_PATH	= ./libft
LIBFT_SRC = ft_atoi.c ft_bzero.c ft_calloc.c \
    ft_putchar_fd.c ft_putstr_fd.c ft_split.c \
    ft_strdup.c ft_strlen.c ft_strncmp.c \
    ft_substr.c ft_atol.c ft_memset.c
PRINTF_SRC = ft_printf.c print_char.c print_conv.c print_hex.c print_int.c print_p.c print_s.c print_unsigned_int.c
LIBFT_NAME	= libft.a
PRINT_PATH	= ./ft_printf
PRINT_NAME	= libftprintf.a

all: $(NAME)
bonus: $(BONUS_NAME)


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@ -MMD


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ) $(OBJ:.o=.d) $(BONUS_OBJ:.o=.d)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

-include $(OBJ:.o=.d) $(BONUS_OBJ:.o=.d)