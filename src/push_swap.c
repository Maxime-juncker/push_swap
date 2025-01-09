/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:48:09 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/09 09:23:02 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	end(t_list *a, t_list *b)
{
	debug_print(a, b, "done");
	check(a);
	ft_lstclear(&a, &free);
	ft_lstclear(&b, &free);
	exit(0);
}

void	start(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 1)
		end(*a, *b);
	debug_print(*a, *b, "Init a and b");
	push_stack(b, a, 'b');
	push_stack(b, a, 'b');
	debug_print(*a, *b, "pb pb");
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	argc--;
	argv++;
	b = NULL;
	a = build_stack(argc, argv);
	if (a == NULL)
		return (0);
	start(&a, &b);
	while (ft_lstsize(a) > 0)
	{
		pass(&a, &b);
		debug_print(a, b, "pass");
	}
	final_pass(&a, &b);
	end(a, b);
}
