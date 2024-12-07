/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:20:49 by mjuncker          #+#    #+#             */
/*   Updated: 2024/12/07 11:36:45 by mjuncker         ###   ########.fr       */
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
	int	val_a = 0;
	int	val_b = 0;

	i = 0;
	ft_printf("----------------------------------------------------\n");
	ft_printf("Exec %s:\n", instruction);
	while ((a != NULL && i < a->len) || (b != NULL && i < b->len))
	{
		if (a != NULL && i < a->len)
		{
			val_a = a->values[a->len - i - 1];
			ft_printf("%d\t", val_a);
		}
		else
			ft_printf("x\t");
		if (b != NULL && i < b->len)
		{
			val_b = b->values[b->len - i - 1];
			ft_printf("%d", val_b);
		}
		else
			ft_printf("x", val_b);

		ft_printf("\t|\t(%s)\t(%s)", get_bin_n(val_a, 4), get_bin_n(val_b, 4));
		// ft_printf("\t|\t(%s)\t(%s)", get_bin(val_a), get_bin(val_b));
		ft_printf("\n");
		i++;
	}
	if (a && b)
		ft_printf("_\t_\na\tb \t len a: %d, len b: %d\n\n", a->len, b->len);
	else if (a)
		ft_printf("_ _\na b \t len a: %d\n\n", a->len);
	else if (b)
		ft_printf("_ _\na b \t len b: %d\n\n", b->len);

}

char	*get_bin(unsigned int n)
{
	char	*res;
	char	*tmp;
	size_t		i = 0;

	tmp = u_ft_itoa_base(n, "01");
	res = ft_calloc(sizeof(int) * 8, sizeof(char)); // sizeof(int) == 4byte == 4 * 8bit
	i = 0;
	while (i < ft_strlen(tmp))
	{
		res[sizeof(int) * 8 - i - 1] = tmp[ft_strlen(tmp) - i - 1];
		i++;
	}
	i = 0;
	while (res[i] == 0)
	{
		res[i] = '0';
		i++;
	}
	free(tmp);
	return (res);
}

char	*get_bin_n(unsigned int nb, int n)
{
	char	*res;
	char	*tmp;
	size_t		i = 0;

	tmp = u_ft_itoa_base(nb, "01");
	res = ft_calloc(n, sizeof(char));
	i = 0;
	while (i < ft_strlen(tmp))
	{
		res[n - i - 1] = tmp[ft_strlen(tmp) - i - 1];
		i++;
	}
	i = 0;
	while (res[i] == 0)
	{
		res[i] = '0';
		i++;
	}
	free(tmp);
	return (res);
}

int	main(int argc, char **argv)
{
	if (argc == 0)
		return (0);
	argc--;
	argv++;
	// ft_printf("bin -42: %s\n", get_bin(-42));
	return (start_solver(argc, argv));

}