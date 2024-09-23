NAME := philo

CC := cc
CFLAGS := -Wall -Werror -Wextra -g

SRCS := philo.c \
		init.c \
		basics.c \
		checker.c \
		philosophing.c \

OBJS := $(SRCS:.c=.o)

%.o: %.c
	@$(CC) -g $(CFLAGS) -c $< -o $@ -I./

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -pthread

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re