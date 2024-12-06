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
	print_stacks(a, b, "init a and b");
	solve(a, b);
	return (0);
}

void	bucket_pass(t_stack *a, t_stack *b, int pass_idx)
{
	int	i;
	int	original_len;
	char	*tmp;

	original_len = a->len;
	i = 0;
	while (i < original_len)
	{
		tmp = get_bin(a->values[a->len - 1]);
		if (tmp[pass_idx] == '1')
			push_stack(a, b);
		else
			rotate_stack(a);
		i++;
	}

}

void	solve(t_stack *a, t_stack *b)
{
	// bucket_pass(a, b, 31);
	// print_stacks(a, b, "pass");

	size_t	i = 28;
	while (i < sizeof(int) * 8)
	{
		bucket_pass(a, b, i);
		print_stacks(a, b, "pass");
		ft_printf("pass: %d\n", i);
		i++;
	}
}
