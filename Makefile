include makerc/colors.mk

# Directories and File Names
NAME		:= cub3d
SRC_DIR		:= src
BUILD_DIR	:= build
MAIN		:= main.c
RM			:= rm -rvf
HEADERS		= include/cubed.h
CC			= gcc


# External Libraries
PATH_MLX	:= ./libs/MLX42
PATH_LIBFT  := ./libs/libft
PATH_PRINTF	:= ./libs/libft/ft_printf


# Include Paths
INCLUDES	= -I $(PATH_LIBFT) -I $(PATH_PRINTF) -I $(PATH_MLX)/include/


# Libraries
# ARCHIVE_MLX		:= $(PATH_MLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
ARCHIVE_MLX		:= $(PATH_MLX)/build/libmlx42.a -L/opt/homebrew/lib -lglfw -ldl -pthread -lm
ARCHIVE_PRINTF	:= $(PATH_PRINTF)/libftprintf.a
ARCHIVE_LIBFT	:= $(PATH_LIBFT)/libft.a


# Compiler Flags
CFLAGS			= -Wall -Wextra -Werror -Wunreachable-code -Ofast
INCLUDE_FLAGS	:= $(addprefix -I, $(sort $(dir $(HEADERS))))

ifdef DEBUG
	CFLAGS += -g
endif

ifdef FSAN
	CFLAGS += -fsanitize=address,undefined
endif


# Source files
SRC =	src/main.c \
		src/drawing/screen.c \
		src/drawing/mini_map.c \
		src/drawing/hooks.c \
		src/drawing/raycasting.c \
		src/drawing/getters.c \
		src/drawing/start_cubed.c \
		src/setup/input_error_handling.c \
		src/setup/input_initialization.c \
		src/setup/parsing.c \
		src/setup/parse_map.c \
		src/setup/parse_color_code.c \
		src/setup/parse_texture.c \
		src/setup/utils.c \
		src/setup/validate_map.c \
		src/setup/get_next_line/get_next_line.c \
		src/setup/get_next_line/get_next_line_utils.c \
		src/cleanup/free_allocations.c


# Object files
OBJS        = $(addprefix $(BUILD_DIR)/, $(SRC:$(SRC_DIR)/%.c=%.o))
MAIN_OBJ    = $(addprefix $(BUILD_DIR)/, $(MAIN:%.c=%.o))


# Targets
all: libmlx $(NAME)

clone_submodule:
	git clone https://github.com/codam-coding-college/MLX42.git ./libs/MLX42

libmlx:
	@cmake $(PATH_MLX) -B $(PATH_MLX)/build && make -C $(PATH_MLX)/build -j4
	@printf "$(MEGENTA_FG)libmlx\n$(RESET_COLOR)"

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(MAKE) -C $(PATH_LIBFT)
	$(MAKE) -C $(PATH_PRINTF)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) $(ARCHIVE_LIBFT) $(ARCHIVE_PRINTF) $(ARCHIVE_MLX) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created_archive\n"

$(MAIN_OBJ) $(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@


# Cleaning Targets
clean:
	@$(RM) $(OBJS) $(MAIN_OBJ)
	$(MAKE) -C $(PATH_LIBFT) clean
	$(MAKE) -C $(PATH_PRINTF) clean

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(PATH_MLX)/build

re: fclean all


# Debugging Targets
debug:
	$(MAKE) DEBUG=1
.PHONY: debug

rebug: fclean debug
.PHONY: rebug

fsan:
	$(MAKE) DEBUG=1 FSAN=1
.PHONY: debug

resan: fclean fsan

.PHONY: all clean fclean re debug rebug fsan resan