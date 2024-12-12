#include "push_swap.h"
#include <math.h>

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

#if PRINT_STEPS
	print_stacks(a, b, "init a and b");
#endif
	solve(a, b);
	return (0);
}

void	sort(t_stack *a, t_stack *b, int pivot_idx)
{
	int	nb_pop = 0;
	int	i = 0;
	int	pivot = b->values[pivot_idx];
	push_stack(b, a);
	if (a->len == 1 || a->values[a->len - 2] < pivot)
		return;
	rotate_stack(a);
	while (a->values[a->len - 1] > pivot)
	{
		push_stack(a, b);
		nb_pop++;
	}
	rrotate_stack(a);
	while (i < nb_pop)
	{
		push_stack(b, a);
		i++;
	}
}

int	power(int a, int n)
{
	int	tmp = a;
	int	i = 1;
	while (i < n)
	{
		a *= tmp;
		i++;
	}
	return (a);
}

int	is_sorted(t_stack *stack)
{
	int	i = 1;

	if (stack->len == 1)
		return (1);
	while (i < stack->len)
	{
		if (stack->values[i] > stack->values[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	pre_pass(t_stack *a, int pass_idx, int i)
{
	int	res = 0;
	while (i < a->len)
	{
		if (a->values[a->len - 1] % power(10, pass_idx) == i)
			res++;
		i++;
	}
	return (res);
}

void	bucket_pass(t_stack *a, t_stack *b, int pass_idx)
{
	int	i = 0;
	int	nb_elem = a->len;
	// int nb_left = pre_pass(a, pass_idx, i);
	while (a->len > 0)
	{
		if (nb_elem == 0)
		{
			nb_elem = a->len;
			// nb_left = pre_pass(a, pass_idx, i);
			i++;
		}
		if (a->values[a->len - 1] % power(10, pass_idx) == i)
		{
			push_stack(a, b);
			// nb_left--;
		}
		else
			rotate_stack(a);
		nb_elem--;
	}
	while (b->len > 0)
		push_stack(b, a);
}

void	solve(t_stack *a, t_stack *b)
{
#if PRINT_STEPS
	ft_printf("====================\n");
	ft_printf("creating buckets\n");
#endif
	int	i = 1;
	while (i < 3)
	{
		bucket_pass(a, b, i);
		i++;
	}
	


#if PRINT_STEPS
	print_stacks(a, b, "finish sorting");
#endif

}
