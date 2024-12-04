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
		ft_printf("[error]: duplicate detected\n");
		cleanup_stack(a);
		cleanup_stack(b);
		exit(1);
	}

	ft_quick_sort(a, b);
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

	pivot_idx = 0;
}

//? assuming that pivot is at the bottom of stack b
//? idea: return 1 if no swap happend, 0 overwise
void	do_swap(t_stack *a, t_stack *b)
{
	int	i = 0;
	int	right = b->values[0];
	int	left = b->values[0];

	i = 0;
	while (i < a->len)
	{
		// at start: left == pivot
		if (a->values[i] > left)
		{
			left = i;
			break;
		}
		i++;
	}

	i = 0;
	while (i < b->len)
	{
		// at start: right == pivot
		if (b->values[i] < right)
		{
			right = i;
			break;
		}
		i++;
	}
	ft_printf("left: %d		|	item: %d\n", left, a->values[left]);
	ft_printf("right: %d	|	item: %d\n", right, b->values[right]);

	//* if right or left are == to b[0] then dont do anything
}

void	ft_quick_sort(t_stack *a, t_stack *b)
{
	int	pivot_idx = 3; // ps c'est aussi un 3 mais tkt


	// 2 6 5 3 8 7 1 0 (init)
	print_stacks(a, b, "init a and b");
	// 2 6 5 8 7 1 0 3 (set pivot to end)
	set_pivot_at_end(a, b, pivot_idx); // put pivot at end
	// print_stacks(a, b, "set pivot to end");

	// swap left and right
	// do_swap(a, b);
	// print_stacks(a, b, "swap left / right");

}
