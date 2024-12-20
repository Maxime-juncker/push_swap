#include <push_swap.h>

void	debug_print(t_list *a, t_list *b, const char *action)
{

	ft_printf("-----------------------\n");
	ft_printf("exec %s:\n", action);
	while (a || b)
	{
		if (a)
			ft_printf("%s\t", a->content);
		else
			ft_printf(".\t");
		if (b)
			ft_printf("%s\n", b->content);
		else
			ft_printf(".\n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_printf("_\t_\na\tb\n");
}

int	get_max(t_list *lst)
{
	int max = ft_atoi(lst->content);

	while (lst)
	{
		if (ft_atoi(lst->content) > max)
			max = ft_atoi(lst->content);
		lst = lst->next;
	}
	return (max);
}

int	is_biggest(int elt, t_list *b)
{
	while (b)
	{
		if (ft_atoi(b->content) > elt)
			return (0);
		b = b->next;
	}
	return (1);
}

/* 2 3 3 4 */

int	get_move_weight(t_list *a, t_list *b, int idx, int elt)
{
	(void)a;
	// cost of putting move on top
	int	top_a_cost = idx; // si idx == 0 alors elt top et donc pas de cout pour rotate a
	int	top_b_cost = 0;
	int	max;

	//=========================================================================
	// if elt is begger than stack b, then elt need to be on top of the max of b
	if (is_biggest(elt, b))
	{
		max = get_max(b);
		while (ft_atoi(b->content) != max && ft_atoi(ft_lstlast(b)->content) != max)
		{
			top_b_cost++;
			b = b->next;
		}
		ft_printf("cost for %d: %d\n", elt, top_a_cost + top_b_cost + 1);
		return (top_a_cost + top_b_cost + 1);
	}
	//=========================================================================

	int	range = 999;
	int tmp = 0;
	int	i = 1;
	while (b)
	{
		tmp = abs(ft_atoi(b->content) - elt);
		if (tmp < range)
		{
			top_b_cost = i;
			range = tmp;
		}
		i++;
		b = b->next;
	}
	return (top_a_cost + top_b_cost + 1);

}

void pass(t_list **a, t_list **b)
{
	int best_weight = 999;
	int i = 0;


	int ra = 0;
	int rb = 0;
	int tmp = 0;
	t_list	*cpy = *a;
	while (cpy)
	{
		tmp = get_move_weight(*a, *b, i, ft_atoi(cpy->content));
		if (tmp < best_weight)
		{
			best_weight = tmp;
			ra = i;
			rb = best_weight - 1 - i;
		}
		cpy = cpy->next;
		i++;
	}


	ft_printf("ra: %d\nrb: %d\n", ra, rb);
	i = 0;
	while (i < ra)
	{
		rotate_a(a);
		i++;
	}
	i = 0;
	while (i < rb)
	{
		rotate_b(b);
		i++;
	}
	push_b(a, b);
	ft_printf("\n\n");

}

int	main(void)
{

	t_list	*a;
	t_list	*b;

	b = NULL;
	a = ft_lstnew("5");
	ft_lstadd_back(&a, ft_lstnew("2"));
	ft_lstadd_back(&a, ft_lstnew("7"));
	ft_lstadd_back(&a, ft_lstnew("1"));
	ft_lstadd_back(&a, ft_lstnew("6"));
	ft_lstadd_back(&a, ft_lstnew("3"));
	ft_lstadd_back(&a, ft_lstnew("9"));
	ft_lstadd_back(&a, ft_lstnew("4"));
	ft_lstadd_back(&a, ft_lstnew("8"));
	debug_print(a, b, "Init a and b");

	// fist push 2 element of a to b
	push_b(&a, &b);
	push_b(&a, &b);

	pass(&a, &b);
	pass(&a, &b);
	pass(&a, &b);
	pass(&a, &b);
	pass(&a, &b);
	pass(&a, &b);
	pass(&a, &b);
	debug_print(a, b, " ");
}