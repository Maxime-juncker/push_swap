NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g3 $(INCLUDES_D)
MAKEFLAGS += --no-print-directory

SRC =	push_swap.c					\
		push_swap_instruction.c		\
		solver.c					\

OBJ = $(SRC:.c=.o)

OBJ_D = obj/
SRCS_D = src/
BIN_D = bin/
INCLUDES_D = -Iincludes/ -Ilibft/includes/

OBJ := $(addprefix $(OBJ_D), $(OBJ))
SRCS := $(addprefix $(SRCS_D), $(SRCS))

# colors
RED 	= \033[31m
GREEN 	= \033[32m
YELLOW 	= \033[33m
RESET 	= \033[0m
BLUE 	= \033[34m

RM = rm -fr

all: $(NAME)

$(NAME): $(OBJ)
	echo "$(YELLOW)[MAKE]: libft$(RESET)"
	$(MAKE)  -C libft
	$(CC) $(CFLAGS) $(OBJ) libft/bin/libft.a -o $(NAME)
	echo "$(YELLOW)[CREATING EXE]: $@$(RESET)"
	echo "$(GREEN)[SUCCESS]: $@$(RESET)"

$(OBJ_D)%.o : $(SRCS_D)%.c includes/push_swap.h | $(OBJ_D)
	echo "$(BLUE)[COMPILING]: $@$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	echo "$(RED)[CLEAN]: obj files$(RESET)"
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ_D)

.PHONY: fclean
fclean: clean
	echo "$(RED)[CLEAN]: binaries$(RESET)"
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	$(RM) $(BIN_D)a.out

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all

.libft:
	$(MAKE) -C ./libft

# Create directories

$(OBJ_D):
	echo "$(YELLOW)[CREATING]: $(OBJ_D)$(RESET)"
	mkdir -p $(OBJ_D)

$(BIN_D):
	echo "$(YELLOW)[CREATING]: $(BIN_D)$(RESET)"
	mkdir -p $(BIN_D)

.SILENT: