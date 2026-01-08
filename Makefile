CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f
NAME    = push_swap
CHECKER = checker

COMMON_SRCS = game.c ft_atoi.c parsing.c stack_utils.c swap.c push.c rotate.c revrotate.c


PS_SRCS = main.c algo.c algo_five_num.c first_arry.c $(COMMON_SRCS)


CHECKER_SRCS = checker.c  strcmp.c $(COMMON_SRCS)


PS_OBJS      = $(PS_SRCS:.c=.o)
CHECKER_OBJS = $(CHECKER_SRCS:.c=.o)


all: $(NAME) bonus


$(NAME): $(PS_OBJS)
	$(CC) $(CFLAGS) $(PS_OBJS) -o $(NAME)


bonus: $(CHECKER)

$(CHECKER): $(CHECKER_OBJS)
	$(CC) $(CFLAGS) $(CHECKER_OBJS) -o $(CHECKER)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	$(RM) $(PS_OBJS) $(CHECKER_OBJS)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all

.PHONY: all bonus clean fclean re