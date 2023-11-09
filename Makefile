.PHONY: 		clean fclean re norm

NAME = cub3d

CC = cc -g3

ifeq ($(shell uname),Linux)
	MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o
	CFLAGS = -Wall -Wextra -Werror -ggdb #-fsanitize=address
	MAKEFLAGS	+= --no-print-directory -s
	MLX_DIR = mlx_linux/
else
	CFLAGS = -Wall -Wextra -Werror -fsanitize=address
	MLXFLAGS = -framework OpenGL -framework AppKit -Lmlx -lmlx -lm
	MLX_DIR = mlx/
endif

# COLORS
RED=\033[0;31m
BLUE=\033[0;34m
GREEN=\033[0;32m
YELLOW=\033[0;33m
END=\033[0m

SRC_DIR = ./sources
OBJ_DIR = .obj
INCLUDES = -I ./includes

LIBFT		= libft/libft.a

MLX_A		= libmlx.a
MLX			= $(addprefix $(MLX_DIR), $(MLX_A))

SRC =	$(SRC_DIR)/main.c			\
		$(SRC_DIR)/parsing.c		\
		$(SRC_DIR)/error.c			\
		$(SRC_DIR)/free.c			\
		$(SRC_DIR)/keys.c			\
		$(SRC_DIR)/display.c		\
		$(SRC_DIR)/parsing_utils.c	\
		$(SRC_DIR)/parse_map.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)


all: $(NAME)

$(NAME): lib $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) $(MLX) $(INCLUDES) -o $(NAME)
	@echo "$(GREEN)Compilation succeded ! ✔️$(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/sources
	@$(CC) $(CFLAGS) $(INCLUDES) -I mlx -c $< -o $@

lib:
	@make -C libft

norm:
	@norminette ./libft | grep "Error" && echo "$(RED)Norminette KO!$(END)" || echo "$(GREEN)Norminette OK!$(END)"

clean:
	@echo "$(YELLOW)All .o files deleted 🗑 $(END)"
		@make clean -C libft
		@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(YELLOW)The final program is deleted 🗑 $(END)"
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean norm all
