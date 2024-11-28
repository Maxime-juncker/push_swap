/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:20:37 by mjuncker          #+#    #+#             */
/*   Updated: 2024/11/28 10:24:50 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *s)
{
	int	tmp;

	if (s->len < 2)
		return ;
	tmp = s->values[s->len - 1];
	s->values[s->len - 1] = s->values[s->len - 2];
	s->values[s->len - 2] = tmp;
}


void	push_stack(t_stack *from, t_stack *dest)
{
	if (from->len == 0)
		return ;
	dest->len++;
	dest->values[dest->len - 1] = from->values[from->len - 1];
	from->values[from->len - 1] = 0;
	from->len--;
}

void	rotate_stack(t_stack *s)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < s->len)
	{
		tmp = s->values[(i + 1) % s->len];
		s->values[(i + 1) % s->len] = s->values[i % s->len];
		s->values[(i) % s->len] = tmp;
		i += 2;
	}
}

void	rrotate_stack(t_stack *s)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < s->len - 1)
	{
		tmp = s->values[i % (s->len)];
		s->values[i % s->len] = s->values[(i+1) % s->len];
		s->values[(i+1) % s->len] = tmp;
		i++;
	}
}

