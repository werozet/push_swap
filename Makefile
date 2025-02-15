# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wzielins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 17:33:38 by wzielins          #+#    #+#              #
#    Updated: 2024/11/28 17:33:43 by wzielins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the final executable
NAME = push_swap

# Source files
SOURCES = sources/operations_rotate.c sources/operations_rrotate.c sources/operations_swap_push.c \
sources/push_swap.c sources/push_swap_utils.c sources/push_swap_utils2.c sources/push_swap_utils3.c \
sources/push_swap_utils4.c sources/sort_for_3.c sources/sort_for_4_to_9.c sources/sort_for_more.c

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes -g

# Paths
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Target for all
all: $(NAME)

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Target for the final executable
$(NAME): $(OBJECTS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

# Clean object files
clean:
	@rm -f $(OBJECTS)
	@make -C $(LIBFT_DIR) clean
	
# Full clean, including the executable and libft
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re