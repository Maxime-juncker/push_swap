#include "push_swap.h"

int	start_solver(int stack_len, char **values)
{
	t_stack	*a;
	t_stack	*b;
	int	i = 0;
	int	len;

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
	print_stacks(a, b, "init a and b");
	len = a->len;
	while (i < len)
	{
		ft_quick_sort(a, b, i);
		i++;
	}
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
	int	pivot = a->values[pivot_idx];
	// int	result = 0;
	// ft_printf("pivot is: %d (%d idx)\n", a->values[pivot_idx], pivot_idx);
	set_pivot_at_end(a, b, pivot_idx);
	while (b->values[b->len - 1] != pivot)
	{
		if (b->values[b->len - 1] < pivot)
			push_stack(b, a);
		else
			rotate_stack(b);
	}
	// print_stacks(a, b, "sorted based on pivot");
	while (b->len > 0)
	{
		push_stack(b, a);
	}
	// print_stacks(a, b, "sorted");
}
