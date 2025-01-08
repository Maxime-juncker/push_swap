/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:35:14 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/08 09:47:06 by mjuncker         ###   ########.fr       */
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

void	check(t_list *a)
{
	while (a->next)
	{
		if (ft_atoi(a->content) > ft_atoi(a->next->content))
		{
			ft_printf("\033[31m==== !! NOT SORTED !! ====\n\033[0m");
			return ;
		}
		a = a->next;
	}
	ft_printf("\033[32m==== SORTED ====\n\033[0m");
}
#else

void	debug_print(t_list *a, t_list *b, const char *action)
{
	(void)a;
	(void)b;
	(void)action;
	return ;
}

void	check(t_list *a)
{
	(void)a;
	return ;
}
#endif
