/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:30:39 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/13 11:21:04 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	final_pass(t_list **a, t_list **b)
{
	int		min;

	while (ft_lstsize(*b) > 0)
	{
		push_stack(a, b, 'a');
	}
	min = get_min(*a);
	if (ft_lstchr_n(*a, min) > ft_lstsize(*a) / 2)
	{
		while (ft_atoi((*a)->content) != min)
		{
			rrotate_stack(a, 'a', NULL);
		}
	}
	else
	{
		while (ft_atoi((*a)->content) != min)
		{
			rotate_stack(a, 'a', NULL);
		}
	}
}

void	exec_set(t_list **a, t_list **b, t_inst_set set)
{
	while (set.ra != 0 || set.rb != 0 || set.rr != 0)
	{
		if (set.rr > 0)
			rr(a, b, &set);
		else if (set.rr < 0)
			rrr(a, b, &set);
		if (set.ra > 0)
			rotate_stack(a, 'a', &set);
		else if (set.ra < 0)
			rrotate_stack(a, 'a', &set);
		if (set.rb > 0)
			rotate_stack(b, 'b', &set);
		else if (set.rb < 0)
			rrotate_stack(b, 'b', &set);
	}
}

int	pass(t_list **a, t_list **b, int original_size)
{
	if (ft_lstsize(*b) == 0)
	{
		push_stack(b, a, 'b');
		push_stack(b, a, 'b');
		debug_print(*a, *b, "pb pb");
	}
	if (original_size < REVERSE_MAX && ft_lstsize(*a) == 3)
	{
		sort_a(a, b);
		return (0);
	}
	exec_set(a, b, get_best_set(a, b));
	push_stack(b, a, 'b');
	if (ft_lstsize(*a) == 0)
		return (0);
	return (1);
}
