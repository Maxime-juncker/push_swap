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

	print_stacks(a, b, "set pivot to end");
}

//? assuming that pivot is at the bottom of stack b
// @return 0 == continue
// @return 1 == stop and reset pivot
// @return 2 == stop and pivot already at right place
int	do_swap(t_stack *a, t_stack *b)
{
	int	i = 0;
	// default right and left to pivot idx
	int	right = -1;
	int	left = -1;

	//* get first value bellow pivot
	i = 0;
	while (i < a->len)
	{
		// at start: left == pivot
		if (a->values[i] > b->values[0])
		{
			left = i;
			break;
		}
		i++;
	}
	//* get first value above pivot
	i = 1;
	while (i < b->len)
	{
		// at start: right == pivot
		if (b->values[i] < b->values[0])
		{
			right = i;
			break;
		}
		i++;
	}

	//* if right or left are == to b[0] then dont do anything
	if (right == -1 && left == -1)
		return (1);
	else if (left == -1) // put pivot at end and return
	{
		while (b->len > 0)
		{
			push_stack(b, a);
		}
		print_stacks(a, b, "swap left / right");
		return (2);
	}
	else if (right == -1) // put pivot at begining
	{
		while (b->len > 0)
		{
			push_stack(b, a);
		}
		rotate_stack(a);
		print_stacks(a, b, "swap left / right");
		return (2);
	}
	ft_printf("left:	%d	|	item:	%d\n", left, a->values[left]);
	ft_printf("right:	%d	|	item:	%d\n\n", right, b->values[right]);

	// switch left and right
	while (left < a->len - 1)
	{
		rotate_stack(a);
		left++;
	}

	// save the pivot
	rrotate_stack(b);
	push_stack(b, a);

	while (right < b->len)
	{
		rotate_stack(b);
		right++;
	}

	// return the pivot to it's original place
	push_stack(a, b);
	rotate_stack(b);

	// switch both stack top
	push_stack(b, a);
	rotate_stack(a);
	push_stack(a, b);

	print_stacks(a, b, "swap left / right");
	return (0);

	// undo to place right and left in the old spot
	//? it may be unecerry to do replace in the old spot
	//? try later without the following code
}

void	reset_pivot(t_stack *a, t_stack *b)
{
	rrotate_stack(b);
	while (b->len > 0)
	{
		push_stack(b, a);
	}
	print_stacks(a, b, "reset pivot");
}

void	ft_quick_sort(t_stack *a, t_stack *b)
{
	int	pivot_idx = 3; // ps c'est aussi un 3 mais tkt
	int	result = 0;

	ft_printf("pivot is: %d (%d idx)\n", a->values[pivot_idx], pivot_idx);
	print_stacks(a, b, "init a and b");
	set_pivot_at_end(a, b, pivot_idx);
	// swap left and right
	while (result == 0)
	{
		result = do_swap(a, b);
	}
	if (result == 1)
		reset_pivot(a, b);

	// put pivot at the right spot
}
