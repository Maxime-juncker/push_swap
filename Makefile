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
ARGS = 329 457 657 839 436 720 355 550
BARGS = 125 872 719 974 393 110 762 193 336 738 380 730 29 258 368 326 794 163 45 543 919 165 609 902 643 288 546 659 270 142 964 213 876 663 807 384 651 28 921 477 890 271 297 647 426 984 809 650 593 463 325 839 111 641 2 903 826 339 816 117 473 67 489 345 946 132 501 269 776 318 247 596 817 657 667 388 16 940 232 822 602 671 674 49 410 545 926 848 328 37 866 437 681 38 672 973 538 654 276 95

all: $(BIN_D)$(NAME)

$(BIN_D)$(NAME): $(OBJ) $(BIN_D)
	echo "$(YELLOW)[MAKE]: libft$(RESET)"
	$(MAKE)  -C libft
	$(CC) $(CFLAGS) $(OBJ) libft/bin/libft.a -o $(BIN_D)$(NAME)
	echo "$(YELLOW)[CREATING EXE]: $@$(RESET)"
	echo "$(GREEN)[SUCCESS]: $@$(RESET)"

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

INSTRUCTION_COUNT = $(shell $(BIN_D)./push_swap $(BARGS) | wc -l)
.PHONY: benchmark
benchmark: all $(LOG_D)
	$(BIN_D)./push_swap $(BARGS) > $(LOG_D)benchmark_$(shell date --iso=seconds).log
	echo "\n==================================================================" >> $(LOG_D)benchmark_$(shell date --iso=seconds).log
	echo "||	push swap took $(INSTRUCTION_COUNT) instructions to sort 100 random numbers	||" >> $(LOG_D)benchmark_$(shell date --iso=seconds).log
	echo "==================================================================\n" >> $(LOG_D)benchmark_$(shell date --iso=seconds).log
	echo "push swap took $(INSTRUCTION_COUNT) instructions to sort 100 random numbers"
	echo "$(BLUE)[SAVED]: $(LOG_D)$(shell date --iso=seconds).log"

.SILENT: