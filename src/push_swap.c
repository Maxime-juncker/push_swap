/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:20:49 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/27 14:15:29 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arr(int *arr, int len, char *name)
{
	int	i;

	i = 0;
	ft_printf("%s: [", name);
	while (i < len - 1)
	{
		ft_printf("%d, ", arr[i]);
		i++;
	}
	ft_printf("%d]\n", arr[i]);
}

void	*cleanup_stack(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	if (stack->values != NULL)
		free(stack->values);
	free(stack);
	return (NULL);
}

int	check_duplicate(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->values[i] == stack->values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stack	*create_stack(char **values, int len)
{
	t_stack	*stack;
	int		i;

	stack = ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->values = ft_calloc(len, sizeof(int));
	if (stack->values == NULL)
		return (cleanup_stack(stack));
	stack->len = 0;
	if (values == NULL)
		return (stack);
	i = 0;
	while (i < len) // ! si prbl alors ajouter un param val_len pour la while
	{
		stack->values[len - i - 1] = ft_atoi(values[i]);
		i++;
	}
	stack->len = len;
	return (stack);
}

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < a->len || i < b->len)
	{
		if (i < a->len)
			ft_printf("%d", a->values[a->len - i - 1]);
		ft_printf(" ");
		if (i < b->len)
			ft_printf("%d", b->values[b->len - i - 1]);
		ft_printf("\n");
		i++;
	}
	ft_printf("_ _\na b \t len a: %d, len b: %d\n\n", a->len, b->len);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 0)
		return (0);
	argv++;
	argc--;
	a = create_stack(argv, argc);
	if (!a)
		return (-1);
	b = create_stack(NULL, argc);
	if (!b)
	{
		cleanup_stack(a);
		return (-1);
	}
	print_stacks(a, b);
	// print_arr(a->values, a->len, "a");
	if (check_duplicate(a))
	{
		ft_printf("[error]: duplicate detected\n");
		cleanup_stack(a);
		cleanup_stack(b);
		exit(1);
	}

	swap_a(a);
	print_stacks(a, b);
	push_b(a, b);
	push_b(a, b);
	push_b(a, b);
	print_stacks(a, b);
	rotate_a(a);
	print_stacks(a, b);
}
