//
// Created by mjuncker on 11/26/24.
//

#include "push_swap.h"

// void sa(int *a, int *b, size_t len)
// {

// }

int	*create_stack(char **v, int len)
{
	int	*stack;
	int	i;

	stack = ft_calloc(len, sizeof(int));
	if (stack == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		stack[i] = ft_atoi(v[i]);
		i++;
	}
	return (stack);
}

void	print_stack(int *stack, int len, char *name)
{
	int	i;

	i = len - 1;
	while (i > 0)
	{
		ft_printf("%d\n", stack[i]);
		i--;
	}
	ft_printf("_\n%s\n", name);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;

	if (argc == 0)
		return (0);
	argc--;
	argv++;
	a = create_stack(argv, argc);
	if (!a)
		return (-1);
	b = ft_calloc(argc, sizeof(int));
	if (!b)
	{
		free(a);
		return (-1);
	}
	print_stack(a, argc, "a");

}