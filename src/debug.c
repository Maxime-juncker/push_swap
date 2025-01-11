/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:35:14 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/11 14:05:20 by mjuncker         ###   ########.fr       */
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
			ft_printf("\033[34m%s\t", a->content);
		else
			ft_printf("\033[34m.\t");
		if (b)
			ft_printf("\033[32m%s\n", b->content);
		else
			ft_printf("\033[32m.\n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_printf("\033[0m_\t_\na\tb\n");
}

int	check(t_list *a)
{
	while (a->next)
	{
		if (ft_atoi(a->content) > ft_atoi(a->next->content))
		{
			error("==== !! NOT SORTED !! ====");
			return (0);
		}
		a = a->next;
	}
	success("==== SORTED ====");
	return (1);
}
#else

void	debug_print(t_list *a, t_list *b, const char *action)
{
	(void)a;
	(void)b;
	(void)action;
	return ;
}

int	check(t_list *a)
{
	while (a->next)
	{
		if (ft_atoi(a->content) > ft_atoi(a->next->content))
		{
			return (0);
		}
		a = a->next;

	}
	return (1);
}
#endif
