/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:48:09 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/07 13:30:36 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*build_stack(int count, char **values)
{
	t_list	*a;
	int		i;

	if (count == 0)
		return (NULL);
	a = NULL;
	i = 0;
	while (i < count)
	{
		ft_lstadd_back(&a, ft_lstnew(values[i]));
		i++;
	}
	return (a);
}

void	check(t_list *a)
{
	while (a->next)
	{
		if (ft_atoi(a->content) > ft_atoi(a->next->content))
		{
			ft_printf("NOT SORTED\n");
			return ;
		}
		a = a->next;
	}
	ft_printf("SORTED\n");
}

void	final_pass(t_list **a, t_list **b)
{
	int		min;

	while (ft_lstsize(*b) > 0)
	{
		push_a(a, b);
	}
	min = get_min(*a);
	if (ft_lstchr_n(*a, min) > ft_lstsize(*a) / 2)
	{
		while (ft_atoi((*a)->content) != min)
		{
			rrotate_a(a);
		}
	}
	else
	{
		while (ft_atoi((*a)->content) != min)
		{
			rotate_a(a);
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	argc--;
	argv++;
	a = build_stack(argc, argv);
	b = NULL;
	debug_print(a, b, "Init a and b");
	push_b(&a, &b);
	push_b(&a, &b);
	debug_print(a, b, "pb pb");
	while (ft_lstsize(a) > 0)
	{
		pass(&a, &b);
		debug_print(a, b, "pass");
	}
	final_pass(&a, &b);
	debug_print(a, b, "done");
	check(a);
}
