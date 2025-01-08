/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:48:09 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/08 12:21:52 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	argc--;
	argv++;
	a = build_stack(argc, argv);
	if (a == NULL)
	{
		return (0);
	}
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
	ft_lstclear(&a, &free);
	ft_lstclear(&b, &free);
}
