# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cova <cova@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 17:58:22 by cleguina          #+#    #+#              #
#    Updated: 2023/12/20 19:07:35 by cova             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strrchr.c \
	ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_atoi.c \
	ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	ft_lstmap.c ft_strcmp.c ft_strjoin_free.c get_next_line.c \
	get_next_line_utils.c ft_free_matrix.c ft_putnbr.c ft_printf.c \
	ft_print_char.c ft_print_countdigit.c ft_print_hex.c \
	ft_print_itoa.c ft_print_nmbr.c ft_print_ptr.c ft_print_putstr.c \
	ft_print_str.c ft_print_strlen.c ft_print_unsig.c ft_print_utoa.c \
		

OBJ = $(SRC:.c=.o)

BOBJS = $(BONUS:.c=.o)

HDR = libft.h 

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)

re: fclean all

bonus: $(NAME) $(BOBJS)
	@ar rcs $(NAME) $(BOBJS)
	
.PHONY: re all clean fclean bonus
