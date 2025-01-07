/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:04:00 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/07 13:58:12 by mjuncker         ###   ########.fr       */
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
void	push_stack(t_list **to, t_list **from, char name);
void	rotate_stack(t_list **s, char name);
void	rrotate_stack(t_list **s, char name);
void	rr(t_list **a, t_list **b);
void	rrr(t_list **a, t_list **b);

// utils.c
void	debug_print(t_list *a, t_list *b, const char *action);

// solver.c
void	pass(t_list **a, t_list **b);

int		get_min(t_list *lst);

#endif //PUSH_SWAP_H