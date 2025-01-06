#include <push_swap.h>

void	debug_print(t_list *a, t_list *b, const char *action)
{
	return;

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

int	get_min(t_list *lst)
{
	int max = ft_atoi(lst->content);

	while (lst)
	{
		if (ft_atoi(lst->content) < max)
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

int	is_min(int elt, t_list *b)
{
	while (b)
	{
		if (ft_atoi(b->content) < elt)
			return (0);
		b = b->next;
	}
	return (1);
}
// 2 3 3 4

// ! marche pas
int	get_move_weight(t_list *a, t_list *b, int idx, int elt)
{
	// debug_print(a, b, "550");
	(void)a;
	// cost of putting move on top
	int	top_a_cost = idx; // si idx == 0 alors elt top et donc pas de cout pour rotate a
	int	top_b_cost = 0;

	if (is_min(elt, b))
	{
		int b_min = get_min(b);
		while (b != NULL && ft_atoi(b->content) != b_min)
		{
			top_b_cost++;
			b = b->next;
		}
		top_b_cost++;

	}
	else if (is_biggest(elt, b))
	{
		int b_biggest = get_max(b);
		while (b != NULL && ft_atoi(b->content) != b_biggest)
		{
			top_b_cost++;
			b = b->next;
		}
	}
	else
	{
		int last = ft_atoi(ft_lstlast(b)->content);
		while (b != NULL)
		{
			if (last > elt && ft_atoi(b->content) < elt)
				break;
			top_b_cost++;
			last = ft_atoi(b->content);
			b = b->next;
		}

	}
	// ft_printf("cost for %d: %d\n\ta: %d\n\tb: %d\n", elt, top_a_cost + top_b_cost + 1, top_a_cost, top_b_cost);

	return (top_a_cost + top_b_cost + 1); // +1 vue que on push
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
			// ft_printf("pass cost for %d: %d\n\ta: %d\n\tb: %d\n", ft_atoi(cpy->content), best_weight, i, best_weight - 1 - i);

		}
		cpy = cpy->next;
		i++;
	}

	// ft_printf("ra: %d\nrb: %d\n", ra, rb);
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
	// ft_printf("\n\n");

}

t_list	*build_stack(int count, char **values)
{
	t_list	*a = 0x0;

	if (count == 0)
		return (NULL);

	int i = 0;
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

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	argc--;
	argv++;
	a = build_stack(argc, argv);
	b = NULL;

	debug_print(a, b, "init a and b");


	// fist push 2 element of a to b
	push_b(&a, &b);
	push_b(&a, &b);
	debug_print(a, b, "pb pb");

	while (ft_lstsize(a) > 0)
	{
		pass(&a, &b);
		debug_print(a, b, "pass");
	}
	while (ft_lstsize(b) > 0)
	{
		push_a(&a, &b);
	}
	// debug_print(a, b, "push a");
	int min = get_min(a);
	while (ft_atoi(a->content) != min)
	{
		rotate_a(&a);
	}
	debug_print(a, b, "done");
	// check(a);
}