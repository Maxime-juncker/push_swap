/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:30:26 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/13 10:55:30 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_3(t_list **a)
{
	int			max;

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
	debug_print(*a, NULL, "a is sorted");
}

int	get_ra(t_list **a, int elt)
{
	t_list		*cpy;
	int			size;
	int			tmp;
	t_inst_set	set;

	cpy = *a;
	set.ra = 0;
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
	return (set.ra);
}

int	get_min_max(t_inst_set *set, int elt, t_list **a)
{
	int	tmp;

	if (get_min(*a) > elt)
	{
		tmp = get_min(*a);
		set->ra = (ft_lstchr_n(*a, tmp));
		return (1);
	}
	else if (get_max(*a) < elt)
	{
		tmp = get_max(*a);
		set->ra = (ft_lstchr_n(*a, tmp) + 1);
		return (1);
	}
	return (0);
}

void	sort_a(t_list **a, t_list **b)
{
	t_inst_set	set;
	int			elt;

	sort_3(a);
	while ((*b) != NULL)
	{
		elt = ft_atoi((*b)->content);
		set.rb = 0;
		set.ra = 0;
		set.rr = 0;
		if (get_min_max(&set, elt, a) == 0)
			set.ra = get_ra(a, elt);
		set = get_rr(set);
		exec_set(a, b, set);
		push_stack(a, b, 'a');
		debug_print(*a, *b, "pass");
	}
}
