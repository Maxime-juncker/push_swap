#include <push_swap.h>

void	swap_a(t_list **a)
{
	if (a == NULL)
		return ;
	if (*a == NULL || ft_lstsize(*a) < 2)
		return ;

	t_list	*tmp;
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;

#if DETAIL_INSTRUCTION
	debug_print(*a, NULL, "sa");
#else
	ft_printf("sa\n");
#endif
}

void	swap_b(t_list **b)
{
	if (b == NULL)
		return ;
	if (*b == NULL || ft_lstsize(*b) < 2)
		return ;

	t_list	*tmp;
	tmp = (*b)->next;
	(*b)->next = tmp->next;
	tmp->next = *b;
	*b = tmp;

#if DETAIL_INSTRUCTION
	debug_print(NULL, *b, "sb");
#else
	ft_printf("sb\n");
#endif
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = (*b)->next;
	ft_lstadd_front(a, *b);
	*b = tmp;

#if DETAIL_INSTRUCTION
	debug_print(*a, *b, "pa");
#else
	ft_printf("pa\n");
#endif
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = tmp;

#if DETAIL_INSTRUCTION
	debug_print(*a, *b, "pb");
#else
	ft_printf("pb\n");
#endif

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

#if DETAIL_INSTRUCTION
	debug_print(*a, NULL, "ra");
#else
	ft_printf("ra\n");
#endif

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

#if DETAIL_INSTRUCTION
	debug_print(*a, NULL, "rra");
#else
	ft_printf("rra\n");
#endif
}

void	rotate_b(t_list **b)
{
	t_list	*tmp;

	tmp = (*b)->next;
	ft_lstlast(*b)->next = *b;
	(*b)->next = NULL;
	*b = tmp;

#if DETAIL_INSTRUCTION
	debug_print(NULL, *b, "rb");
#else
	ft_printf("rb\n");
#endif

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

#if DEBUG
	debug_print(*a, *b, "rrb");
#else
	ft_printf("rrb\n");
#endif
}

