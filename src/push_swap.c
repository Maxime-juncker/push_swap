/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:20:49 by mjuncker          #+#    #+#             */
/*   Updated: 2024/12/04 15:58:51 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*create_stack(char **values, int len, const char name)
{
	t_stack	*stack;
	int		i;

	stack = ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->name = name;
	stack->values = ft_calloc(len, sizeof(int));
	if (stack->values == NULL)
		return (cleanup_stack(stack));
	stack->len = 0;
	if (values == NULL)
		return (stack);
	i = 0;
	while (i < len)
	{
		stack->values[len - i - 1] = ft_atoi(values[i]);
		i++;
	}
	stack->len = len;
	return (stack);
}

void	print_stacks(t_stack *a, t_stack *b, char *instruction)
{
	int	i;

	i = 0;
	ft_printf("----------------------------------------------------\n");
	ft_printf("Exec %s: \n", instruction);
	while ((a != NULL && i < a->len) || (b != NULL && i < b->len))
	{
		if (a != NULL && i < a->len)
			ft_printf("%d", a->values[a->len - i - 1]);
		else
			ft_printf(" ");
		ft_printf(" ");
		if (b != NULL && i < b->len)
			ft_printf("%d", b->values[b->len - i - 1]);
		ft_printf("\n");
		i++;
	}
	if (a && b)
		ft_printf("_ _\na b \t len a: %d, len b: %d\n\n", a->len, b->len);
	else if (a)
		ft_printf("_ _\na b \t len a: %d\n\n", a->len);
	else if (b)
		ft_printf("_ _\na b \t len b: %d\n\n", b->len);

}

int	main(int argc, char **argv)
{
	if (argc == 0)
		return (0);
	argc--;
	argv++;
	return (start_solver(argc, argv));

}
