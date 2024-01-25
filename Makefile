include makerc/colors.mk

################################################################################

NAME	:= cub3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42
CC		= gcc
rm		:= rm -rvf

################################################################################

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

################################################################################

INCLUDES	= -I ./libft -I ./libft/ft_printf
PRINTF 		= ./lib/libft/ft_printf/libftprintf.a
LIBFT 		= ./lib/libft/libft.a

################################################################################

SRCS	:= \
	src/main.c \
	src/drawing/screen.c \
	src/drawing/mini_map.c \
	src/drawing/hooks.c \
	src/drawing/raycasting.c \
	src/drawing/getters.c \
	src/drawing/start_cubed.c
# src/drawing/temp_maps.c


OBJS	:= ${SRCS:.c=.o}

################################################################################

ifdef	DEBUG
	CFLAGS		+=-g
endif

ifdef	FSAN
	CFLAGS		+=-fsanitize=address,undefined
endif

################################################################################

all: libmlx libft $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
	@printf "$(MEGENTA_FG)libmlx\n$(RESET_COLOR)"

libft:
	$(MAKE) -C ./lib/libft
	$(MAKE) -C ./lib/libft/ft_printf
	@printf "$(MEGENTA_FG)libft\n$(RESET_COLOR)"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) $(INCLUDES) && printf "Compiling: $(BRIGHT_CYAN_FG)$(notdir $<)\n$(RESET_COLOR)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(LIBS) $(HEADERS) $(INCLUDES) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(LIBMLX)/build

debug:
	$(MAKE) DEBUG=1
.PHONY: debug

rebug: fclean debug
.PHONY: rebug

fsan:
	$(MAKE) DEBUG=1 FSAN=1
.PHONY: debug

resan: fclean fsan
.PHONY: resan

fclean: clean
	@$(RM) $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx