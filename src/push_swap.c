/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:48:09 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/08 09:40:27 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*build_stack(int count, char **values)
{
	t_list	*a;
	int		i;

	if (count == 0)
		return (NULL);
	a = NULL;
	i = 0;
	while (i < count)
	{
		ft_lstadd_back(&a, ft_lstnew(values[i]));
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	argc--;
	argv++;
	a = build_stack(argc, argv);
	b = NULL;
	debug_print(a, b, "Init a and b");
	push_stack(&b, &a, 'b');
	push_stack(&b, &a, 'b');
	debug_print(a, b, "pb pb");
	while (ft_lstsize(a) > 0)
	{
		pass(&a, &b);
		debug_print(a, b, "pass");
	}
	final_pass(&a, &b);
	debug_print(a, b, "done");
	check(a);
}
