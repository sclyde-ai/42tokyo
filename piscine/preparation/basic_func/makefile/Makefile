# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
OBJS_DIR = srcs
INCLUDES_DIR = includes
SRCS = $(SRCS_DIR)/ft_putchar.c $(SRCS_DIR)/ft_swap.c $(SRCS_DIR)/ft_putstr.c $(SRCS_DIR)/ft_strlen.c $(SRCS_DIR)/ft_strcmp.c
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	@echo "Library $(NAME) created."

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "Temporary object files cleaned."

fclean: clean
	rm -f $(NAME)
	@echo "All binaries removed."

re: fclean all

# Makefile execution behaviors
.PHONY: all clean fclean re
