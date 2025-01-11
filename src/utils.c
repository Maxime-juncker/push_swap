/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:21:42 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/10 12:50:58 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_max(t_list *lst)
{
	int	max;

	max = ft_atoi(lst->content);
	while (lst)
	{
		if (ft_atoi(lst->content) > max)
			max = ft_atoi(lst->content);
		lst = lst->next;
	}
	return (max);
}

int	get_min(t_list *lst)
{
	int	min;

	min = ft_atoi(lst->content);
	while (lst)
	{
		if (ft_atoi(lst->content) < min)
			min = ft_atoi(lst->content);
		lst = lst->next;
	}
	return (min);
}
