NAME = pushswap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f

SRCS = algo.c  algo_five_num.c  first_arry.c  ft_atoi.c  main.c  parsing.c  push.c  revrotate.c  rotate.c  stack_utils.c  swap.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJ) 
				$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
.SECONDARY: