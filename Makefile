# =========================
#		cub3D
# =========================
NAME = cub3D
UNAME_S := $(shell uname -s)

# === MINILIBX ===
ifeq ($(UNAME_S), Linux)
	MLX_DIR  = minilibx-linux
	MLX_NAME = $(MLX_DIR)/libmlx_Linux.a
	MLX_FLAGS = -L $(MLX_DIR) -lmlx_Linux -L/usr/X11/lib -lXext -lX11 -lm
else ifeq ($(UNAME_S), Darwin) # macOS
	MLX_DIR  = minilibx_opengl_20191021
	MLX_NAME = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

# === LIBFT ===
LIBFT_DIR = libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a

# === GNL ===
GNL_DIR = get_next_line
GNL_NAME = $(GNL_DIR)/get_next_line.a

# === DIR ===
SRC_DIR = src
OBJ_DIR = obj

# === SRC ===
SRCS = \
	src/main.c

# === OBJ ===
OBJS = \
	obj/main.o

# === COMPILATION ===
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INC_DIR = . $(LIBFT_DIR) $(GNL_DIR) $(MLX_DIR)
HEADERS = $(addprefix -I,$(INC_DIR))

# === CLEAN ===
RM = rm -f
RM_DIR = rm -rf

# =====================================================

all: $(LIBFT_NAME) $(GNL_NAME) $(MLX_NAME) $(NAME)

$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL_NAME):
	$(MAKE) -C $(GNL_DIR)

$(MLX_NAME):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS) $(GNL_NAME) $(LIBFT_NAME) $(MLX_NAME)
	$(CC) $(CFLAGS) $(HEADERS) $(OBJS) $(GNL_NAME) \
	$(LIBFT_NAME) $(MLX_NAME) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM_DIR) $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	$(RM) $(NAME)

re: fclean all

val-%: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes --trace-children=yes --track-fds=yes --undef-value-errors=yes ./$(NAME) $(@:val-%=./map/%.cub)

.PHONY: all clean fclean re val-%
