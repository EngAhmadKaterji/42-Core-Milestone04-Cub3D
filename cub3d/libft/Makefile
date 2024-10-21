# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Library name
NAME = libft.a

# Source files
SRCS = get_next_line.c get_next_line_utils.c ft_isdigit.c ft_memcpy.c ft_atoi.c ft_bzero.c ft_calloc.c \
       ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
       ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
       ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
       ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
       ft_tolower.c ft_toupper.c ft_skip_spaces.c ft_is_whitespace.c ft_strcmp.c ft_free_array.c ft_is_char.c ft_strjoin_modified.c\
							ft_free_array_to_y.c

# Bonus source files
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
        ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstdelone.c

# Object files
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

# Colors and effects
RESET = \033[0m
BOLD = \033[1m
CYAN = \033[36m
GREEN = \033[32m
YELLOW = \033[33m

# Rules
all: header $(NAME)

header:
	@echo "$(CYAN)=============================$(RESET)"
	@echo "$(CYAN)=  $(BOLD)Compiling libft...   $(RESET)$(CYAN)=$(RESET)"
	@echo "$(CYAN)=============================$(RESET)"

$(NAME): $(OBJS) $(BONUS_OBJS)
	@echo "$(YELLOW)Creating library $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)Library $(NAME) created successfully!$(RESET)"

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: header $(BONUS_OBJS) $(OBJS)
	@echo "$(YELLOW)Adding bonus objects to $(NAME)...$(RESET)"
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(GREEN)Bonus added successfully!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "$(GREEN)Clean complete!$(RESET)"

fclean: clean
	@echo "$(YELLOW)Removing library $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)Full clean complete!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus header
