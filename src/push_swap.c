#include <push_swap.h>

void	debug_print(t_list *a, t_list *b, const char *action)
{
	return ;
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

int	is_max(int elt, t_list *b)
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

t_inst_set	get_instruction_set(t_list *a, t_list *b, int idx, int elt)
{
	// debug_print(a, b, "550");
	(void)a;
	t_inst_set	set;
	// cost of putting move on top
	if (ft_lstchr_n(a, elt) > ft_lstsize(a) / 2)
	{
		set.ra = (ft_lstsize(a) - ft_lstchr_n(a, elt)) * -1; // -1 to tell that it's in reverse
	}
	else
	{
		set.ra = idx; // si idx == 0 alors elt top et donc pas de cout pour rotate a
	}
	set.rb = 0;
	set.rr = 0;

	if (is_min(elt, b))
	{
		int b_min = get_min(b);
		if (ft_lstchr_n(b, b_min) > ft_lstsize(b) / 2)
			set.rb = (ft_lstsize(b) - ft_lstchr_n(b, b_min) - 1) * -1;
		else
			set.rb = ft_lstchr_n(b, b_min) + 1;
	}
	else if (is_max(elt, b))
	{
		int b_biggest = get_max(b);
		if (ft_lstchr_n(b, b_biggest) > ft_lstsize(b) / 2)
			set.rb = (ft_lstsize(b) - ft_lstchr_n(b, b_biggest)) * -1;
		else
			set.rb = ft_lstchr_n(b, b_biggest);
	}
	else
	{
		int last = ft_atoi(ft_lstlast(b)->content);
		int size = ft_lstsize(b);
		while (b != NULL)
		{
			if (last > elt && ft_atoi(b->content) < elt)
				break;
			set.rb++;
			last = ft_atoi(b->content);
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

	// ft_printf("cost for %d: %d\n\ta: %d\n\tb: %d\n", elt, top_a_cost + top_b_cost + 1, top_a_cost, top_b_cost);
	set.weight = abs(set.ra) + abs(set.rb) + abs(set.rr) + 1; // +1 vue que on push
	return (set);
}

void pass(t_list **a, t_list **b)
{
	int i = 0;

	t_inst_set set;
	t_inst_set best_set = {9999, 9999, 9999, 9999};
	t_list	*cpy = *a;
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

	// ft_printf("ra: %d\nrb: %d\n", ra, rb);
	while (best_set.ra != 0 || best_set.rb != 0 || best_set.rr != 0)
	{
		if (best_set.rr > 0)
		{
			rr(a, b);
			best_set.rr--;
		}
		else if (best_set.rr < 0)
		{
			rrr(a, b);
			best_set.rr++;
		}
		if (best_set.ra > 0)
		{
			rotate_a(a);
			best_set.ra--;
		}
		else if (best_set.ra < 0)
		{
			rrotate_a(a);
			best_set.ra++;
		}
		if (best_set.rb > 0)
		{
			rotate_b(b);
			best_set.rb--;
		}
		else if (best_set.rb < 0)
		{
			rrotate_b(b);
			best_set.rb++;
		}
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

	a = NULL;
	b = NULL;

	// ft_lstadd_back(&a, ft_lstnew("4"));
	// ft_lstadd_back(&b, ft_lstnew("19"));
	// ft_lstadd_back(&b, ft_lstnew("13"));
	// ft_lstadd_back(&b, ft_lstnew("9"));
	// ft_lstadd_back(&b, ft_lstnew("8"));
	// ft_lstadd_back(&b, ft_lstnew("7"));
	// ft_lstadd_back(&b, ft_lstnew("6"));
	// ft_lstadd_back(&b, ft_lstnew("5"));
	// ft_lstadd_back(&b, ft_lstnew("2"));
	// ft_lstadd_back(&b, ft_lstnew("1"));
	debug_print(a, b, "Init a and b");

	// pass(&a, &b);
	// debug_print(a, b, "pass");
	// return 0;
	argc--;
	argv++;
	a = build_stack(argc, argv);
	b = NULL;

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
	int min = get_min(a);

	if (ft_lstchr_n(a, min) > ft_lstsize(a) / 2)
	{
		while (ft_atoi(a->content) != min)
		{
			rrotate_a(&a);
		}
	}
	else
	{
		while (ft_atoi(a->content) != min)
		{
			rotate_a(&a);
		}

	}
	debug_print(a, b, "done");
	check(a);
}
