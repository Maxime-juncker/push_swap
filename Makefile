NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -g3 $(INCLUDES_D)
MAKEFLAGS += --no-print-directory

SRC =	push_swap.c					\
		push_swap_instruction.c		\

OBJ = $(SRC:.c=.o)

OBJ_D = obj/
SRCS_D = src/
BIN_D = bin/
LOG_D = log/
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
ARGS = 377 523 738 909 254
R_ARGS=$(shell python3 rand_numbers.py)

all:
	$(MAKE) libft
	$(MAKE) $(BIN_D)$(NAME)

.PHONY: libft
libft:
	$(MAKE) -C libft


$(BIN_D)$(NAME): $(OBJ) $(BIN_D)
	$(CC) $(CFLAGS) $(OBJ) libft/bin/libft.a -o $(BIN_D)$(NAME)
	@echo "$(GREEN)[SUCCESS]$(RESET)"

$(OBJ_D)%.o : $(SRCS_D)%.c includes/push_swap.h | $(OBJ_D)
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

INSTRUCTION_COUNT = $(shell $(BIN_D)./push_swap $(R_ARGS) | wc -l)
.PHONY: benchmark
benchmark: all $(LOG_D)
	$(BIN_D)./push_swap $(R_ARGS) > $(LOG_D)benchmark_$(shell date --iso=seconds).log
	echo "\n==================================================================" >> $(LOG_D)benchmark_$(shell date --iso=seconds).log
	echo "||	push swap took $(INSTRUCTION_COUNT) instructions to sort 500 random numbers	||" >> $(LOG_D)benchmark_$(shell date --iso=seconds).log
	echo "==================================================================\n" >> $(LOG_D)benchmark_$(shell date --iso=seconds).log
	echo "push swap took $(INSTRUCTION_COUNT) instructions to sort 500 random numbers"
	echo "$(BLUE)[SAVED]: $(LOG_D)$(shell date --iso=seconds).log"

visu: all
	make -C push_swap_visualizer/build/
	./push_swap_visualizer/build/bin/visualizer

.SILENT: