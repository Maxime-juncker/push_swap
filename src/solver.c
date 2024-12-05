#include "push_swap.h"

int	start_solver(int stack_len, char **values)
{
	t_stack	*a;
	t_stack	*b;

	a = create_stack(values, stack_len, 'a');
	if (!a)
		return (-1);
	b = create_stack(NULL, stack_len, 'b');
	if (!b)
	{
		cleanup_stack(a);
		return (-1);
	}
	if (check_duplicate(a))
	{
		ft_printf("error\n");
		cleanup_stack(a);
		cleanup_stack(b);
		exit(1);
	}
	// print_stacks(a, b, "init a and b");
	ft_quick_sort(a, b, a->len - 1);
	// print_stacks(a, b, "end");
	return (0);
}

void set_pivot_at_end(t_stack *a, t_stack *b, int pivot_idx)
{
	while (a->len > pivot_idx + 1) // make pivot top of list
	{
		push_stack(a, b);
	}
	rrotate_stack(b);
	push_stack(a, b);
	rotate_stack(b);
	while (a->len > 0)
	{
		push_stack(a, b);
	}
	// print_stacks(a, b, "set pivot to end");
}

void	ft_quick_sort(t_stack *a, t_stack *b, int pivot_idx)
{
	int	nb_pop = 0; // usefull to know how many item do we need to push back in
	int	pivot = a->values[pivot_idx];
	int	i = 0;
	// check for numbers > to pivot
	push_stack(a, b);

	// set pivot to end;
	rotate_stack(b);

	while (b->values[b->len - 1] > pivot)
	{
		push_stack(b, a);
		nb_pop++;
	}
	rrotate_stack(b);
	while (i < nb_pop)
	{
		push_stack(a, b);
		i++;
	}

	if (a->len > 0)
		ft_quick_sort(a, b, a->len - 1);
	else
	{
		while (b->len > 0)
		{
			push_stack(b, a);
		}
	}
}
