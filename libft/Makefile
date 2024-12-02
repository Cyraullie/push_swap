# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 11:31:20 by cgoldens          #+#    #+#              #
#    Updated: 2024/12/02 15:50:40 by cgoldens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
RM = rm -rf

SRC = ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isalnum.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_printf_utils1.c ft_printf_utils2.c ft_printf.c \
		get_next_line_utils.c get_next_line.c handle_error.c ft_strcmp.c \
		ft_atol.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ = $(SRC:.c=.o)

GREEN = \033[1;32m
CYAN = \033[1;36m
YELLOW = \033[1;33m
RESET = \033[0m

# Règles
all: header $(NAME)

header:
	@echo "$(GREEN)"
	@echo "    __    _ __    ______ "
	@echo "   / /   (_) /_  / __/ /_"
	@echo "  / /   / / __ \/ /_/ __/"
	@echo " / /___/ / /_/ / __/ /_  "
	@echo "/_____/_/_.___/_/  \__/  "
	@echo "                         "
	@echo "$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) ./ -c -o $@ $<

$(NAME): $(OBJ)
	@echo "$(GREEN)Linking all objects $(NAME)...$(RESET)"
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "$(CYAN)Build completed!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(RM) $(OBJ)

fclean: clean
	@echo "$(YELLOW)Cleaning Libft...$(RESET)"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
