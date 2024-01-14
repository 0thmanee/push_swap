CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBFT = ./libft/libft.a
PRINTF = ./ft_printf/libftprintf.a

NAME = push_swap
CFILES = push_swap.c parsing.c
OFILES = $(CFILES:.c=.o)
INCLUDES = push_swap.h libft/libft.h ft_printf/ft_printf.h

all: $(NAME)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Program Created"


$(NAME): $(OFILES) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $^ -o $@ $(LIBFT) $(PRINTF)

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@printf "\033[32m %s\n\033[0m" "Creating..."
	@make -C ./libft

$(PRINTF):
	@make -C ./ft_printf

clean:
	@printf "\033[32m %s\n\033[0m" "Cleaning..."
	@$(RM) $(OFILES)
	@make -s clean -C ./libft
	@make -s clean -C ./ft_printf

fclean: clean
	@$(RM) $(NAME)
	@make -s fclean -C ./libft
	@make -s fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re bonus