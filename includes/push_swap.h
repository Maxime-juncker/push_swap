/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:04:00 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/07 13:41:56 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef DEBUG
#  define DEBUG 0
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
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rrotate_a(t_list **a);
void	rotate_b(t_list **a);
void	rrotate_b(t_list **a);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);

// utils.c
void	debug_print(t_list *a, t_list *b, const char *action);

// solver.c
void	pass(t_list **a, t_list **b);

int	get_min(t_list *lst);

#endif //PUSH_SWAP_H