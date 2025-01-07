/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:57:37 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/07 13:11:43 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_max(t_list *lst)
{
	int	max;

	max = ft_atoi(lst->content);
	while (lst)
	{
		if (ft_atoi(lst->content) > max)
			max = ft_atoi(lst->content);
		lst = lst->next;
	}
	return (max);
}

int	get_min(t_list *lst)
{
	int	min;

	min = ft_atoi(lst->content);
	while (lst)
	{
		if (ft_atoi(lst->content) < min)
			min = ft_atoi(lst->content);
		lst = lst->next;
	}
	return (min);
}

static t_inst_set	get_instruction_set(t_list *a, t_list *b, int idx, int elt)
{
	t_inst_set	set;
	int			tmp;
	int			size;

	size = ft_lstsize(b);
	tmp = 0;
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
	if (get_min(b) > elt)
	{
		tmp = get_min(b);
		if (ft_lstchr_n(b, tmp) > ft_lstsize(b) / 2)
			set.rb = (ft_lstsize(b) - ft_lstchr_n(b, tmp) - 1) * -1;
		else
			set.rb = ft_lstchr_n(b, tmp) + 1;
	}
	else if (get_max(b) < elt)
	{
		tmp = get_max(b);
		if (ft_lstchr_n(b, tmp) > ft_lstsize(b) / 2)
			set.rb = (ft_lstsize(b) - ft_lstchr_n(b, tmp)) * -1;
		else
			set.rb = ft_lstchr_n(b, tmp);
	}
	else
	{
		tmp = ft_atoi(ft_lstlast(b)->content);
		while (b != NULL)
		{
			if (tmp > elt && ft_atoi(b->content) < elt)
				break ;
			set.rb++;
			tmp = ft_atoi(b->content);
			b = b->next;
		}
		if (set.rb > size / 2)
			set.rb = (size - set.rb) * -1;
	}
	while (set.ra > 0 && set.rb > 0)
	{
		set.rr++;
		set.ra--;
		set.rb--;
	}
	while (set.ra < 0 && set.rb < 0)
	{
		set.rr--;
		set.ra++;
		set.rb++;
	}
	set.weight = abs(set.ra) + abs(set.rb) + abs(set.rr) + 1;
	return (set);
}

void	exec_set(t_list **a, t_list **b, t_inst_set set)
{
	while (set.ra != 0 || set.rb != 0 || set.rr != 0)
	{
		if (set.rr > 0)
		{
			rr(a, b);
			set.rr--;
		}
		else if (set.rr < 0)
		{
			rrr(a, b);
			set.rr++;
		}
		if (set.ra > 0)
		{
			rotate_a(a);
			set.ra--;
		}
		else if (set.ra < 0)
		{
			rrotate_a(a);
			set.ra++;
		}
		if (set.rb > 0)
		{
			rotate_b(b);
			set.rb--;
		}
		else if (set.rb < 0)
		{
			rrotate_b(b);
			set.rb++;
		}
	}
}

void	pass(t_list **a, t_list **b)
{
	t_inst_set	set;
	t_inst_set	best_set;
	t_list		*cpy;
	int			i;

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
	push_b(a, b);
}
