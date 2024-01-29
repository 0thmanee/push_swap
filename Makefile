CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
CFILES = push_swap.c src/sort_a_to_b_0.c src/sort_a_to_b_1.c src/sort_b_to_a_0.c src/sort_b_to_a_1.c src/parse_0.c src/parse_1.c src/parse_2.c src/parse_3.c instructions/swap.c instructions/push.c instructions/rotate.c instructions/rrotate.c
OFILES = $(CFILES:.c=.o)
INCLUDES = push_swap.h

NAME_BONUS = checker
CFILES_BONUS = bonus/checker_bonus.c bonus/tools_bonus_0.c bonus/tools_bonus_1.c bonus/tools_bonus_2.c bonus/tools_bonus_3.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c bonus/instrs_bonus/swap.c bonus/instrs_bonus/push.c bonus/instrs_bonus/rotate.c bonus/instrs_bonus/rrotate.c
OFILES_BONUS = $(CFILES_BONUS:.c=.o)
INCLUDES_BONUS = bonus/checker_bonus.h

all: $(NAME)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Program Created"


$(NAME): $(OFILES)
	@$(CC) $(CFLAGS) $^ -o $@

bonus: $(NAME_BONUS)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Checker Created"

$(NAME_BONUS): $(OFILES_BONUS)
	@$(CC) $(CFLAGS) $^ -o $@

bonus/%.o: bonus/%.c $(INCLUDES_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OFILES) $(OFILES_BONUS)

fclean: clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@printf "\033[32m[ ✔ ] %s\n\033[0m" "Cleaning Done"

re: fclean all

.PHONY: all clean fclean re bonus