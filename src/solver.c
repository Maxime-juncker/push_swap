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


int	pre_pass(t_stack *a, int pass_idx, int value)
{
#if PRINT_STEPS
	ft_printf("====== PASS %d (%d) ======\n", pass_idx, value);
#endif
	int	res = 0;
	int	i = 0;
	while (i < a->len)
	{
		if (a->values[i] / power(10, pass_idx) % 10 == value)
			res++;
		i++;
	}
	return (res);
}

void	bucket_pass(t_stack *a, t_stack *b, int pass_idx)
{
	int	i = 0;
	int	nb_elem = a->len;
	int nb_left = pre_pass(a, pass_idx, i);
	while (a->len > 0)
	{
		if (nb_elem == 0)
		{
			i++;
			nb_elem = a->len;
			nb_left = pre_pass(a, pass_idx, i);
		}
		if (a->values[a->len - 1] / power(10, pass_idx) % 10 == i)
		{
			push_stack(a, b);
			nb_left--;
			nb_elem--;
		}
		else if (nb_left == 0)
		{
			i++;
			nb_elem = a->len;
			nb_left = pre_pass(a, pass_idx, i);
		}
		else
		{
			nb_elem--;
			rotate_stack(a);
		}
	}
	while (b->len > 0)
		push_stack(b, a);
}

int	get_biggest_len(t_stack *a)
{
	int	i;
	int	max_len;
	int	tmp;

	i = 0;
	max_len = 0;
	while (i < a->len)
	{
		tmp = ft_strlen(ft_itoa(a->values[i]));
		if (tmp > max_len)
			max_len = tmp;
		i++;
	}
	return (max_len);
}

void	solve(t_stack *a, t_stack *b)
{
#if PRINT_STEPS
	ft_printf("====================\n");
	ft_printf("creating buckets\n");
#endif
	int	i = 0;
	int	max = get_biggest_len(a);
	while (i < max)
	{
		bucket_pass(a, b, i);
		i++;
	}

#if PRINT_STEPS
	print_stacks(a, b, "finish sorting");
#endif

}
