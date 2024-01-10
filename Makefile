CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a

NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -o $(NAME) push_swap.c parsing.c $(LIBFT) $(PRINTF)

$(LIBFT):
	@make -s -C ./libft

$(PRINTF):
	@make -s -C ./ft_printf

clean:
	@make -s clean -C ./libft
	@make -s clean -C ./ft_printf

fclean: clean 
	@make -s fclean -C ./libft
	@make -s fclean -C ./ft_printf
	@$(RM) $(NAME)

re: fclean bonus clean