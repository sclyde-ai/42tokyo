# Variables
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_memset.c ft_memcpy.c ft_memmove.c
OBJS = $(SRCS:%.c=%.o)


# Rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Makefile execution behaviors
.PHONY: all clean fclean re

# # Variables
# NAME = libft.a
# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# SRCS_DIR = srcs
# OBJS_DIR = srcs
# INCLUDES_DIR = includes
# SRCS = $(SRCS_DIR)/ft_strlen.c $(SRCS_DIR)/ft_strlcpy.c $(SRCS_DIR)/ft_strlcat.c $(SRCS_DIR)/ft_strchr.c 
# OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)


# # Rules
# all: $(NAME)

# $(NAME): $(OBJS)
# 	ar rcs $(NAME) $(OBJS)

# $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
# 	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)

# re: fclean all

# # Makefile execution behaviors
# .PHONY: all clean fclean re