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

int	main(void)
{

	t_list	*a;
	a = ft_lstnew(ft_strdup("2"));
	ft_lstadd_back(&a, ft_lstnew(ft_strdup("1")));
	ft_lstadd_back(&a, ft_lstnew(ft_strdup("3")));
	ft_lstadd_back(&a, ft_lstnew(ft_strdup("6")));
	ft_lstadd_back(&a, ft_lstnew(ft_strdup("5")));
	ft_lstadd_back(&a, ft_lstnew(ft_strdup("8")));
	ft_lstprint(a);
	t_list	*b;
	b = 0x0;
	debug_print(a, b, "Init a and b");
	swap_a(&a);
	debug_print(a, b, "sa");
	push_b(&a, &b);
	push_b(&a, &b);
	push_b(&a, &b);
	debug_print(a, b, "pb pb pb");
	rotate_a(&a);
	rotate_b(&b);
	debug_print(a, b, "rr");
	rrotate_a(&a);
	rrotate_b(&b);
	debug_print(a, b, "rrr");
	swap_a(&a);
	debug_print(a, b, "sa");
	push_a(&a, &b);
	push_a(&a, &b);
	push_a(&a, &b);
	debug_print(a, b, "pa pa pa");

}