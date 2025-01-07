/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:04:00 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/07 13:11:35 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef PRINT_STEPS
#  define PRINT_STEPS 0
# endif

# include "libft.h"

typedef struct s_inst_set
{
	int		ra;
	int		rb;
	int		rr;
	size_t	weight;
}	t_inst_set;

// push_swap_instruction.c
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rrotate_a(t_list **a);
void	rotate_b(t_list **a);
void	rrotate_b(t_list **a);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);

// push_swap
void	debug_print(t_list *a, t_list *b, const char *action);

// solver
void	pass(t_list **a, t_list **b);

#endif //PUSH_SWAP_H
int	get_min(t_list *lst);
