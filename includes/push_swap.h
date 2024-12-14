/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:04:00 by mjuncker          #+#    #+#             */
/*   Updated: 2024/12/14 10:10:07 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef DETAIL_INSTRUCTION
# define DETAIL_INSTRUCTION 0
# endif

# ifndef PRINT_STEPS
# define PRINT_STEPS 1
# endif

# include "libft.h"

typedef struct s_stack
{
	char name;
	int	*values;
	int	len;
}	t_stack;

// push_swap
void	*cleanup_stack(t_stack *stack);
int		check_duplicate(t_stack *stack);
t_stack	*create_stack(char **values, int len, const char name);
void	print_stacks(t_stack *a, t_stack *b, char *instruction);

// solver
int	start_solver(int stack_len, char **values);
void	solve(t_stack *a, t_stack *b);
char	*get_bin(unsigned int n);
char	*get_bin_n(unsigned int nb, int n);


// intruction
void	swap_stack(t_stack *s);
void	push_stack(t_stack *from, t_stack *dest);
void	rotate_stack(t_stack *s);
void	rrotate_stack(t_stack *s);

#endif //PUSH_SWAP_H
