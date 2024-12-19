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
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = (*b)->next;
	ft_lstadd_front(a, *b);
	*b = tmp;
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	tmp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = tmp;
}

void	rotate_a(t_list **a)
{
	t_list	*tmp;

	tmp = (*a)->next;
	ft_lstlast(*a)->next = *a;
	(*a)->next = NULL;
	*a = tmp;

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
}

void	rotate_b(t_list **b)
{
	t_list	*tmp;

	tmp = (*b)->next;
	ft_lstlast(*b)->next = *b;
	(*b)->next = NULL;
	*b = tmp;

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
}

