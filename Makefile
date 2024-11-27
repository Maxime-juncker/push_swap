# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 12:19:24 by mjuncker          #+#    #+#              #
#    Updated: 2024/11/20 09:26:59 by mjuncker         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.out
CFLAGS = -Wall -Wextra -Werror $(INCLUDES_D)

SRC = push_swap.c
OBJ = $(SRC:.c=.o)

OBJ_D = obj/
SRCS_D = src/
BIN_D = bin/
INCLUDES_D = -Iincludes/ -Ilibft/includes/

OBJ := $(addprefix $(OBJ_D), $(OBJ))
SRCS := $(addprefix $(SRCS_D), $(SRCS))

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) libft/bin/libft.a -o $(NAME)

$(OBJ_D)%.o : $(SRCS_D)%.c includes/push_swap.h | $(OBJ_D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	$(RM) $(BIN_D)a.out

.PHONY: libft
libft:
	$(MAKE) -C ./libft

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE) re -C ./libft
	$(MAKE) all

# Create directories
$(OBJ_D):
	mkdir -p $(OBJ_D)

$(BIN_D):
	mkdir -p $(BIN_D)

# debug targets
.PHONY: debug
debug:
	$(MAKE) so -C ./libft
	$(CFLAGS) += -g3
	$(MAKE) all
.PHONY: run
run: debug
	@./$(BIN_D)a.out

.PHONY: valgrind
valgrind: debug
	@valgrind --leak-check=full bin/a.out