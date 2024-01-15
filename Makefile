# nombre programa

NAME = pipex

#NAME_BONUS = pipex_bonus

# compilador
CC = gcc #-g

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address

LIB = ar rcs


LIBFT_DIR = ./Libft
LIBFT_PATH		= $(LIBFT_DIR)/libft.a


SRC = src/pipex.c src/pipex_utils.c

SRCB = srcb/pipex_bonus.c srcb/pipex_utils_bonus.c

OBJS = $(SRC:.c=.o)

BOBJS = $(SRCB:.c=.o)


$(NAME): $(LIBFT_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH) $(LIB_SYS) -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME_BONUS): $(LIBFT_PATH) $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) $(LIBFT_PATH) $(LIB_SYS) -o $(NAME_BONUS)

$(BOBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


$(LIBFT_PATH):
			@make -s -C $(LIBFT_DIR)

# Agrega los archivos objeto a la lista de archivos secundarios
all: $(NAME)

bonus: $(NAME_BONUS) $(BOBJS)
	@ar rcs $(NAME_BONUS) $(BOBJS)

clean:
			@rm -f $(OBJS) $(BOBJS)
			@make clean -s -C $(LIBFT_DIR)
			
fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	rm -f $(NAME) $(NAME_BONUS)


re: fclean all


.PHONY: re all clean fclean bonus


