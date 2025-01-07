/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:21:42 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/07 13:30:29 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

#if DEBUG

void	debug_print(t_list *a, t_list *b, const char *action)
{
	ft_printf("-----------------------\n");
	ft_printf("exec %s:\n", action);
	while (a || b)
	{
		if (a)
			ft_printf("%s\t", a->content);
		else
			ft_printf(".\t");
		if (b)
			ft_printf("%s\n", b->content);
		else
			ft_printf(".\n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_printf("_\t_\na\tb\n");
}
#else

void	debug_print(t_list *a, t_list *b, const char *action)
{
	(void)a;
	(void)b;
	(void)action;
	return ;
}

#endif