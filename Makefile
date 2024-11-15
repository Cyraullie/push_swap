# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 11:31:20 by cgoldens          #+#    #+#              #
#    Updated: 2024/11/15 15:30:38 by cgoldens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LIBFT_PATH = libft/
LIBFT = ./libft/libft.a
RM = rm -rf

SRCS = main.c swap.c push.c rotate.c reverse.c check.c sort.c utils.c sort_utils.c

OBJS = $(SRCS:.c=.o)

GREEN = \033[1;32m
CYAN = \033[1;36m
YELLOW = \033[1;33m
RESET = \033[0m

# Règles
all: header $(NAME)

header:
	@echo "$(GREEN)"
	@echo "    ____             __        _____                   "
	@echo "   / __ \__  _______/ /_      / ___/      ______ _____ "
	@echo "  / /_/ / / / / ___/ __ \     \__ \ | /| / / __ \`/ __ \\"
	@echo " / ____/ /_/ (__  ) / / /    ___/ / |/ |/ / /_/ / /_/ /"
	@echo "/_/    \__,_/____/_/ /_/____/____/|__/|__/\__,_/ .___/ "
	@echo "                      /_____/                 /_/      "
	@echo "$(RESET)"


%.o: %.c
	@$(CC) $(CFLAGS) -I ./ -c -o $@ $<

$(LIBFT):
	@echo "$(GREEN)Building Libft...$(RESET)"
	$(MAKE) -s -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT)
	@echo "$(GREEN)Linking all objects and Libft to create $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(CYAN)Build completed!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(MAKE) clean -s -C $(LIBFT_PATH) 
	$(RM) $(OBJS)

fclean: clean
	@echo "$(YELLOW)Cleaning $(NAME) binary and Libft...$(RESET)"
	$(MAKE) fclean -s -C $(LIBFT_PATH) 
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
