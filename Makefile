# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cova <cova@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 19:54:55 by cleguina          #+#    #+#              #
#    Updated: 2023/12/20 19:03:47 by cova             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# nombre programa

NAME = pipex

# compilador
CC = gcc #-g

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

LIB = ar rcs


LIBFT_DIR = ./Libft
LIBFT_PATH		= $(LIBFT_DIR)/libft.a


SRC = src/pipex.c

OBJS = $(SRC:.c=.o)


$(NAME): $(LIBFT_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) $(LIB_SYS) -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH):
			@make -s -C $(LIBFT_DIR)

# Agrega los archivos objeto a la lista de archivos secundarios
all: $(NAME)

clean:
			@rm -f $(OBJS)
			@make clean -s -C $(LIBFT_DIR)
			
fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	rm -f $(NAME)


re: fclean all

# bonus: $(NAME) $(BOBJS)
#	@ar rcs $(NAME) $(BOBJS)

.PHONY: re all clean fclean 