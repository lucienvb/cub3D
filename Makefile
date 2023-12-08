include makerc/colors.mk

################################################################################

NAME			:= cub3D
SRC_DIR			:= src
BUILD_DIR		:= build
MAIN			:= main.c
INCLUDE_DIR		:= include
RM				:= rm -rvf

HEADERS			= $(INCLUDE_DIR)/cub3D.h
CC				= gcc

################################################################################

CFLAGS			= -Wall -Wextra -Werror -Wpedantic
INCLUDE_FLAGS	:= $(addprefix -I, $(sort $(dir $(HEADERS))))

ifdef	DEBUG
	CFLAGS		+=-g
endif

ifdef	FSAN
	CFLAGS		+=-fsanitize=address,undefined
endif

################################################################################

# Source files
SRC = \


################################################################################

# Object files
OBJS       = $(addprefix $(BUILD_DIR)/, $(SRC:%.c=%.o))
MAIN_OBJ   = $(addprefix $(BUILD_DIR)/, $(MAIN:%.c=%.o))

################################################################################

all: $(NAME)

$(NAME): SHELL :=/bin/bash

$(NAME): $(OBJS) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $^ $(INCLUDE_FLAGS) -o $(NAME)
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(MAIN_OBJ) $(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(HEADER)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

################################################################################

clean:
	@$(RM) $(OBJS) $(MAIN_OBJ)

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

re: fclean all

.PHONY: all clean fclean re