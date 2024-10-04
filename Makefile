######################
## MAKE FILE BASICS ##
######################

NAME := philo

CC := cc
CFLAGS := -Wall -Werror -Wextra 

SRCS := philo.c \
		init.c \
		basics.c \
		checker.c \
		philosophing.c \
		utils_philo.c

OBJS := $(SRCS:.c=.o)

%.o: %.c
	@$(CC) -g $(CFLAGS) -c $< -o $@ -I./

######################
## MAKE FILE COLORS ##
######################


CLR_RMV         := \033[0m
RED                 := \033[1;31m
GREEN           := \033[1;32m
YELLOW          := \033[1;33m
BLUE            := \033[1;34m
CYAN            := \033[1;36m


######################
## MAKE FILE CONFIG ##
######################

all: $(NAME)

$(NAME): ${OBJS}
	@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
	$(CC) -o $(NAME) $(OBJS) -pthread -g -fsanitize=thread
	@echo "$(GREEN)$(NAME) created ✔️"



clean:
		@rm -f $(OBJS)
		@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean: clean
		@rm -f $(NAME)
		@ echo "$(RED)Deleting $(CYAN)$(NAME) $(NAME_BONUS) $(CLR_RMV)binary ✔️"

re: fclean all

.PHONY: all clean fclean re
