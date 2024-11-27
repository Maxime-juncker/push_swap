/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:20:37 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/27 15:17:18 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a)
{
	int	tmp;

	if (a->len < 2)
		return ;
	tmp = a->values[a->len - 1];
	a->values[a->len - 1] = a->values[a->len - 2];
	a->values[a->len - 2] = tmp;
}
void	swap_b(t_stack *b)
{
	int	tmp;

	if (b->len < 2)
		return ;
	tmp = b->values[b->len - 1];
	b->values[b->len - 1] = b->values[b->len - 2];
	b->values[b->len - 2] = tmp;
}

void	push_a(t_stack *a, t_stack *b)
{
	if (b->len == 0)
		return ;
	a->len++;
	a->values[a->len - 1] = b->values[b->len - 1];
	b->values[b->len - 1] = 0;
	b->len--;
}

void	push_b(t_stack *a, t_stack *b)
{
	if (a->len == 0)
		return ;
	b->len++;
	b->values[b->len - 1] = a->values[a->len - 1];
	a->values[a->len - 1] = 0;
	a->len--;
}

/*
	5
	8
	6
*/

void	rotate_a(t_stack *a)
{
	int	tmp;
	int	i;

	i = 0;
	(void)tmp;
	while (i < a->len)
	{
		tmp = a->values[a->len - i];
		a->values[a->len - i] = a->values[a->len - i - 1];
		a->values[a->len - i - 1] = tmp;
		i++;
	}
	ft_printf("\n\n");
}

// ? maybe reverse_rotate ???
// void	rotate_a(t_stack *a)
// {
// 	int	tmp;
// 	int	i;

// 	i = 0;
// 	while (i < a->len - 1)
// 	{
// 		tmp = a->values[i % (a->len)];
// 		a->values[i % a->len] = a->values[(i+1) % a->len];
// 		a->values[(i+1) % a->len] = tmp;
// 		i++;
// 	}
// }