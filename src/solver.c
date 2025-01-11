/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:57:37 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/11 11:50:02 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_rb_inner(t_list *b, int elt)
{
	int	tmp;
	int	rb;
	int	size;

	rb = 0;
	size = ft_lstsize(b);
	tmp = ft_atoi(ft_lstlast(b)->content);
	while (b != NULL)
	{
		if (tmp > elt && ft_atoi(b->content) < elt)
			break ;
		rb++;
		tmp = ft_atoi(b->content);
		b = b->next;
	}
	if (rb > size / 2)
		rb = (size - rb) * -1;
	return (rb);
}

int	get_rb(t_list *b, int elt)
{
	int			tmp;

	tmp = 0;
	if (get_min(b) > elt)
	{
		tmp = get_min(b);
		if (ft_lstchr_n(b, tmp) > ft_lstsize(b) / 2)
			return ((ft_lstsize(b) - ft_lstchr_n(b, tmp) - 1) * -1);
		else
			return (ft_lstchr_n(b, tmp) + 1);
	}
	else if (get_max(b) < elt)
	{
		tmp = get_max(b);
		if (ft_lstchr_n(b, tmp) > ft_lstsize(b) / 2)
			return ((ft_lstsize(b) - ft_lstchr_n(b, tmp)) * -1);
		else
			return (ft_lstchr_n(b, tmp));
	}
	return (get_rb_inner(b, elt));
}

t_inst_set	get_rr(t_inst_set set)
{
	int		tmp;

	if (set.rb > 0 && set.ra > 0)
	{
		tmp = ft_min(set.ra, set.rb);
		set.rr = tmp;
		set.ra -= tmp;
		set.rb -= tmp;
	}
	if (set.ra < 0 && set.rb < 0)
	{
		tmp = ft_max(set.ra, set.rb);
		set.rr = tmp;
		set.ra -= tmp;
		set.rb -= tmp;
	}
	return (set);
}

t_inst_set	get_instruction_set(t_list *a, t_list *b, int idx, int elt)
{
	t_inst_set	set;

	set.rb = 0;
	set.rr = 0;
	if (ft_lstchr_n(a, elt) > ft_lstsize(a) / 2)
	{
		set.ra = (ft_lstsize(a) - ft_lstchr_n(a, elt)) * -1;
	}
	else
	{
		set.ra = idx;
	}
	set.rb = get_rb(b, elt);
	set = get_rr(set);
	set.weight = ft_abs(set.ra) + ft_abs(set.rb) + ft_abs(set.rr) + 1;
	return (set);
}
