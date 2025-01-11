/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:30:39 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/11 14:05:23 by mjuncker         ###   ########.fr       */
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

static void	exec_set(t_list **a, t_list **b, t_inst_set set)
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

void	sort_3(t_list **a, t_list **b)
{
	int	max;

	max = get_max(*a);
	while (ft_atoi(ft_lstlast(*a)->content) != max)
	{
		if (ft_lstchr_n(*a, max) == 0)
			rotate_stack(a, 'a', NULL);
		else
			rrotate_stack(a, 'a', NULL);
	}
	if (ft_atoi((*a)->content) > ft_atoi((*a)->next->content))
		swap_stack(a, 'a');
	debug_print(*a, *b, "a is sorted");

		t_inst_set	set;
	while ((*b) != NULL)
	{
		int elt = ft_atoi((*b)->content);
		int tmp;
		set.rb = 0;
		set.ra = 0;
		set.rr = 0;
		if (get_min(*a) > elt)
		{
			tmp = get_min(*a);

				set.ra = (ft_lstchr_n(*a, tmp));
		}
		else if (get_max(*a) < elt)
		{
			tmp = get_max(*a);
			// if (ft_lstchr_n(*a, tmp) > ft_lstsize(*a) / 2)
			// 	set.ra = (ft_lstsize(*a) - ft_lstchr_n(*a, tmp) - 1) * -1;
			// else
				set.ra = (ft_lstchr_n(*a, tmp) + 1);
		}
		else
		{
			int	tmp;
			int	size;
			t_list *cpy = *a;

			size = ft_lstsize(cpy);
			tmp = ft_atoi(ft_lstlast(cpy)->content);
			while (cpy != NULL)
			{
				if (tmp < elt && ft_atoi(cpy->content) > elt)
					break ;
				set.ra++;
				tmp = ft_atoi(cpy->content);
				cpy = cpy->next;
			}
			if (set.ra > size / 2)
				set.ra = (size - set.ra) * -1;
		}
		exec_set(a, b, set);
		push_stack(a, b, 'a');
		debug_print(*a, *b, "pass");

	}

}
int	pass(t_list **a, t_list **b, int original_size)
{
	t_inst_set	set;
	t_inst_set	best_set;
	t_list		*cpy;
	int			i;

	if (original_size < 10 && ft_lstsize(*a) == 3)
	{
		sort_3(a, b);
		return (0);
	}
	cpy = *a;
	best_set.weight = MAX_INT;
	i = 0;
	while (cpy)
	{
		set = get_instruction_set(*a, *b, i, ft_atoi(cpy->content));
		if (set.weight < best_set.weight)
		{
			best_set = set;
		}
		cpy = cpy->next;
		i++;
	}
	exec_set(a, b, best_set);
	push_stack(b, a, 'b');
	if (ft_lstsize(*a) == 0)
		return (0);
	return (1);
}
