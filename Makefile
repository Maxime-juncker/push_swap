NAME = push_swap
CFLAGS = -Wall -Wextra -Werror $(INCLUDES_D)
# CFLAGS = -Wall -Wextra -Werror $(INCLUDES_D) -g3 -D DEBUG=1
MAKEFLAGS += --no-print-directory

SRC =	push_swap.c					\
		push_swap_instruction.c		\
		solver_a.c					\
		solver_b.c					\
		utils.c						\
		pass.c						\
		debug.c						\
		parser.c					\
		errors.c					\

OBJ = $(SRC:.c=.o)

OBJ_D = obj/
SRCS_D = src/
BIN_D = bin/
LOG_D = log/
INCLUDES_D = -Iincludes/ -Ilibft/includes/


OBJ := $(addprefix $(OBJ_D), $(OBJ))
SRCS := $(addprefix $(SRCS_D), $(SRCS))

# colors
RESET 	= \033[0m
RED 	= \033[31m
GREEN 	= \033[32m
YELLOW 	= \033[33m
BLUE 	= \033[34m

RM = rm -fr
ARGS = 451 222 117 441 280
R_ARGS=$(shell python3 rand_numbers.py)

all:
	$(MAKE) libft
	$(MAKE) $(BIN_D)$(NAME)

.PHONY: libft
libft:
	$(MAKE) -C libft


$(BIN_D)$(NAME): $(OBJ) $(BIN_D)
	$(CC) $(CFLAGS) $(OBJ) libft/bin/libft.a -o $(BIN_D)$(NAME)
	echo "$(GREEN)[SUCCESS]$(RESET)"

$(OBJ_D)%.o : $(SRCS_D)%.c includes/push_swap.h libft/bin/libft.a Makefile | $(OBJ_D)
	echo "$(BLUE)[COMPILING]: $@$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clog
	$(RM) $(OBJ_D)
	echo "$(RED)[CLEAN]: obj files$(RESET)"

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	$(RM) $(BIN_D)
	echo "$(RED)[CLEAN]: binaries$(RESET)"

.PHONY: clog
clog:
	$(RM) $(LOG_D)
	echo "$(RED)[CLEAN]: log$(RESET)"

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) all

# Create directories
$(OBJ_D):
	echo "$(YELLOW)[CREATING]: $(OBJ_D)$(RESET)"
	mkdir -p $(OBJ_D)

$(LOG_D):
	echo "$(YELLOW)[CREATING]: $(LOG_D)$(RESET)"
	mkdir -p $(LOG_D)

$(BIN_D):
	echo "$(YELLOW)[CREATING]: $(BIN_D)$(RESET)"
	mkdir -p $(BIN_D)

.PHONY: debug
debug: all $(LOG_D)
	$(BIN_D)./push_swap $(ARGS) > $(LOG_D)$(shell date --iso=seconds).log
	cat $(LOG_D)$(shell date --iso=seconds).log
	echo "$(BLUE)[SAVED]: $(LOG_D)$(shell date --iso=seconds).log"

.PHONY: rdebug
rdebug: all $(LOG_D)
	$(BIN_D)./push_swap $(R_ARGS) > $(LOG_D)$(shell date --iso=seconds).log
	cat $(LOG_D)$(shell date --iso=seconds).log
	echo "$(BLUE)[SAVED]: $(LOG_D)$(shell date --iso=seconds).log"

INSTRUCTION_COUNT =  | wc -l)
.PHONY: benchmark
valgrind: all $(LOG_D)
	$(shell valgrind --leak-check=full ./$(BIN_D)push_swap $(R_ARGS) > $(LOG_D)benchmark_$(shell date --iso=seconds).log)
	echo "$(BLUE)[SAVED]: $(LOG_D)$(shell date --iso=seconds).log"

visu: all
	make -C push_swap_visualizer/build/
	./push_swap_visualizer/build/bin/visualizer

.SILENT: