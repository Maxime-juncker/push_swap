/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:04:00 by mjuncker          #+#    #+#             */
/*   Updated: 2024/12/20 13:15:06 by mjuncker         ###   ########.fr       */
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

// push_swap_instruction.c
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rrotate_a(t_list **a);
void	rotate_b(t_list **a);
void	rrotate_b(t_list **a);


// push_swap
void	debug_print(t_list *a, t_list *b, const char *action);

#endif //PUSH_SWAP_H
