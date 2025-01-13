/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:48:09 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/13 09:01:34 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	end(t_list *a, t_list *b)
{
	debug_print(a, b, "done");
	check(a);
	if (a)
		ft_lstclear(&a, &free);
	if (b)
		ft_lstclear(&b, &free);
	exit(0);
}

void	swap_stack(t_list **s, char name)
{
	t_list	*tmp;

	if (s == NULL)
		return ;
	if (*s == NULL || ft_lstsize(*s) < 2)
		return ;
	tmp = (*s)->next;
	(*s)->next = tmp->next;
	tmp->next = *s;
	*s = tmp;
	ft_printf("s%c\n", name);
}


void	start(t_list **a, t_list **b)
{
	if (check(*a) || ft_lstsize(*a) == 1)
		end(*a, *b);
	debug_print(*a, *b, "Init a and b");
	if (ft_lstsize(*a) == 2)
	{
		swap_stack(a, 'a');
		end(*a, *b);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		original_size;

	argc--;
	argv++;
	b = NULL;
	a = build_stack(argc, argv);
	if (a == NULL)
		return (0);
	original_size = ft_lstsize(a);
	start(&a, &b);
	while (pass(&a, &b, original_size))
	{
		debug_print(a, b, "pass");
	}
	final_pass(&a, &b);
	end(a, b);
}
