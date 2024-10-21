# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx -I/usr/include/X11 -I/usr/include/X11/extensions -I./libft -I./includes -g
LDFLAGS = -Lmlx -lmlx -L./libft -lft -lX11 -lXext -lm

# Output executable name
NAME = cub3d

# Directories
SRC_DIR = src
MLX_DIR = mlx
INCLUDES_DIR = includes
LIBFT_DIR = ./libft

# Source files
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/ft_check_closed_map.c $(SRC_DIR)/ft_exit_free.c \
	  $(SRC_DIR)/ft_init_params.c $(SRC_DIR)/ft_parser.c $(SRC_DIR)/ft_read_map.c \
	  $(SRC_DIR)/ft_texture_utils.c $(SRC_DIR)/ft_parser_utils.c $(SRC_DIR)/ft_move.c \
	  $(SRC_DIR)/ft_cast_ray.c $(SRC_DIR)/ft_cast_ray_utils.c $(SRC_DIR)/ft_cast_floor_ceiling.c \
	  $(SRC_DIR)/ft_cast_floor_ceiling_utils.c $(SRC_DIR)/ft_load_texture.c $(SRC_DIR)/ft_rotate.c \
	  $(SRC_DIR)/ft_mlx.c $(SRC_DIR)/ft_error_message.c

# Object files
OBJ = $(SRC:.c=.o)

# Libft library
LIBFT = $(LIBFT_DIR)/libft.a

# ANSI color codes
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

# Rules

all: welcome $(NAME)

# Welcome message with animation
welcome:
	@echo "$(YELLOW)-------------------------------------------------$(RESET)"
	@echo "$(YELLOW)|       Welcome to the cub3d Project Build!       |$(RESET)"
	@echo "$(YELLOW)-------------------------------------------------$(RESET)"
	@echo "$(YELLOW)Compiling cub3d project...$(RESET)"
	@sleep 0.5
	@echo "$(GREEN)█$(RESET) Initializing..."
	@sleep 0.5
	@echo "$(GREEN)███$(RESET) Loading source files..."
	@sleep 0.5
	@echo "$(GREEN)█████$(RESET) Compiling objects..."
	@sleep 0.5
	@echo "$(GREEN)███████$(RESET) Linking files..."
	@sleep 0.5
	@echo "$(GREEN)█████████$(RESET) Build complete! 🚀"
	@echo "$(GREEN)-------------------------------------------------$(RESET)"
	@if [ -z "$(OBJ)" ]; then \
		echo "$(YELLOW)Nothing to be done!$(RESET)"; \
	fi

# Compile the project, ensuring that libft is built first
$(NAME): $(LIBFT) $(OBJ)
	@if [ -z "$(OBJ)" ]; then \
		echo "$(YELLOW)Nothing to be done!$(RESET)"; \
	else \
		echo "$(BLUE)Linking object files...$(RESET)"; \
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS); \
		echo "$(GREEN)Build successful!$(RESET)"; \
	fi

# Build libft
$(LIBFT):
	@echo "$(BLUE)Building libft library...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) -s

# Compile object files
%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean -s

# Clean object files and executable
fclean: clean
	@echo "$(YELLOW)Cleaning executable...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean -s

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
