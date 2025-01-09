/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:32:07 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/09 09:20:37 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_stack(t_list **to, t_list **from, char name)
{
	t_list	*tmp;

	if (ft_lstsize(*from) == 0)
		return ;
	tmp = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = tmp;
	ft_printf("p%c\n", name);
}

void	rr(t_list **a, t_list **b, t_inst_set *set)
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
	set->rr--;
	ft_printf("rr\n");
}

void	rrr(t_list **a, t_list **b, t_inst_set *set)
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
	set->rr++;
	ft_printf("rrr\n");
}

void	rotate_stack(t_list **s, char name, t_inst_set *set)
{
	t_list	*tmp;

	tmp = (*s)->next;
	ft_lstlast(*s)->next = *s;
	(*s)->next = NULL;
	*s = tmp;
	ft_printf("r%c\n", name);
	if (set == NULL)
		return ;
	if (name == 'a')
		set->ra--;
	else
		set->rb--;
}

void	rrotate_stack(t_list **s, char name, t_inst_set *set)
{
	t_list	*tmp;

	tmp = *s;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *s;
	*s = tmp->next;
	tmp->next = NULL;
	ft_printf("rr%c\n", name);
	if (set == NULL)
		return ;
	if (name == 'a')
		set->ra++;
	else
		set->rb++;
}
