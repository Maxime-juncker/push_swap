/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:32:07 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/07 12:32:33 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap_a(t_list **a)
{
	t_list	*tmp;

	if (a == NULL)
		return ;
	if (*a == NULL || ft_lstsize(*a) < 2)
		return ;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_list **b)
{
	t_list	*tmp;

	if (b == NULL)
		return ;
	if (*b == NULL || ft_lstsize(*b) < 2)
		return ;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;
	ft_printf("sb\n");
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = (*b)->next;
	ft_lstadd_front(a, *b);
	*b = tmp;
	ft_printf("pa\n");
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = tmp;
	ft_printf("pb\n");
}

void	rr(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (ft_lstsize(*a) > 1)
	{
		tmp = (*a)->next;
		ft_lstlast(*a)->next = *a;
		(*a)->next = NULL;
		*a = tmp;
	}
	if (ft_lstsize(*b) > 1)
	{
		tmp = (*b)->next;
		ft_lstlast(*b)->next = *b;
		(*b)->next = NULL;
		*b = tmp;
	}
	ft_printf("rr\n");
}

void rrr(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
	ft_printf("rrr\n");
}

void	rotate_a(t_list **a)
{
	t_list	*tmp;

	tmp = (*a)->next;
	ft_lstlast(*a)->next = *a;
	(*a)->next = NULL;
	*a = tmp;
	ft_printf("ra\n");
}

void	rrotate_a(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	ft_printf("rra\n");
}

void	rotate_b(t_list **b)
{
	t_list	*tmp;

	tmp = (*b)->next;
	ft_lstlast(*b)->next = *b;
	(*b)->next = NULL;
	*b = tmp;
	ft_printf("rb\n");
}

void	rrotate_b(t_list **b)
{
	t_list	*tmp;

	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
	ft_printf("rrb\n");
}
