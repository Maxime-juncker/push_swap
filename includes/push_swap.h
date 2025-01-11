/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:04:00 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/11 13:47:35 by mjuncker         ###   ########.fr       */
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
void		push_stack(t_list **to, t_list **from, char name);
void		rotate_stack(t_list **s, char name, t_inst_set *set);
void		rrotate_stack(t_list **s, char name, t_inst_set *set);
void		rr(t_list **a, t_list **b, t_inst_set *set);
void		rrr(t_list **a, t_list **b, t_inst_set *set);

// utils.c
int			get_min(t_list *lst);
int			get_max(t_list *lst);

// solver.c
t_inst_set	get_instruction_set(t_list *a, t_list *b, int idx, int elt);
int	get_rb(t_list *b, int elt);

// pass.c
void		final_pass(t_list **a, t_list **b);
int			pass(t_list **a, t_list **b, int original_size);
void		swap_stack(t_list **a, char action);

// parser.c
t_list		*build_stack(int count, char **values);

// debug.c
void		debug_print(t_list *a, t_list *b, const char *action);
int		check(t_list *a);

#endif //PUSH_SWAP_H