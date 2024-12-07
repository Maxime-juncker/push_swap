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

#if PRINT_STEPS
	print_stacks(a, b, "init a and b");
#endif
	solve(a, b);
	return (0);
}

void	bucket_pass(t_stack *a, t_stack *b, int pass_idx)
{
	int	i;
	int	original_len;
	char	*tmp;
	int	stop_after = 0;
	int	nb_push = 0;

	original_len = a->len;
	i = 0;
	// pre pass
	while (i < original_len)
	{
		tmp = get_bin(a->values[i]);
		if (tmp[pass_idx] == '1')
			stop_after++;
		i++;
	}

	i = 0;
	// full pass
	while (i < original_len && nb_push < stop_after)
	{
		tmp = get_bin(a->values[a->len - 1]);
		if (tmp[pass_idx] == '1')
		{
			push_stack(a, b);
			nb_push++;
		}
		else
			rotate_stack(a);
		i++;
	}

}


void	sort(t_stack *a, t_stack *b, int pivot_idx)
{
	int	nb_pop = 0;
	int	i = 0;
	int	pivot = b->values[pivot_idx];

	push_stack(b, a);
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
	if (b->len > 0)
		sort(a, b, b->len - 1);
	else
	{
		while (a->len > 0)
		{
			push_stack(a, b);
		}
	}
}

void	solve(t_stack *a, t_stack *b)
{
#if PRINT_STEPS
	ft_printf("====================\n");
	ft_printf("creating buckets\n");
#endif
	// !! pass need to start at 1 not 0
	// !! bin[0] is the msb which tell us the sign
	size_t	i = 1;
	while (i < sizeof(int) * 8)
	{
		bucket_pass(a, b, i);
		i++;
	}

#if PRINT_STEPS
	print_stacks(a, b, "buckets created");
	ft_printf("====================\n");
	ft_printf("sorting buckets\n");
#endif
	//loop over the buckets
	int	last_bin_idx = 31;
	int	j = b->len-1;
	while (j >= 0)
	{
		if (get_bin(b->values[j])[last_bin_idx-1] == '1')
		{
			ft_printf("===========\nnew bucket\n");
			last_bin_idx--;
		}
		ft_printf("%d\t(%s) [%c]\n", b->values[j], get_bin(b->values[j]), get_bin(b->values[j])[last_bin_idx-1]);
		j--;
	}


	//sort(a, b, b->len - 1);
// #if PRINT_STEPS
// 	print_stacks(a, b, "finish sorting");
// #endif

}
