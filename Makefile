CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
CFILES = push_swap.c src/sort_a_to_b_0.c src/sort_a_to_b_1.c src/sort_b_to_a_0.c src/sort_b_to_a_1.c src/parse_0.c src/parse_1.c src/parse_2.c src/parse_3.c instructions/swap.c instructions/push.c instructions/rotate.c instructions/rrotate.c
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