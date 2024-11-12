# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 11:31:20 by cgoldens          #+#    #+#              #
#    Updated: 2024/11/12 15:58:43 by cgoldens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LIBFT_PATH = libft/
LIBFT = ./libft/libft.a
RM = rm -rf

SRCS = main.c

OBJS = $(SRCS:.c=.o)

# Règles
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I ./ -c -o $@ $<

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_PATH)
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -s -C $(LIBFT_PATH) 
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) clean -s -C $(LIBFT_PATH) 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
