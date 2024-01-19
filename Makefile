CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
CFILES = parsing.c tools.c
OFILES = $(CFILES:.c=.o)
INCLUDES = push_swap.h

all: $(NAME)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Program Created"


$(NAME): $(OFILES)
	@$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OFILES)

fclean: clean
	@$(RM) $(NAME)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Cleaning Done"

re: fclean all

.PHONY: all clean fclean re bonus