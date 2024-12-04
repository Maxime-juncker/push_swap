/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:20:37 by mjuncker          #+#    #+#             */
/*   Updated: 2024/12/04 15:53:59 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * the two top element of a stack
 * @note Does nothing if stack len < 2
 * @param s the stack to swap*/
void	swap_stack(t_stack *s)
{
	int	tmp;
	char instruction[3];

	if (s->len < 2)
		return ;
	tmp = s->values[s->len - 1];
	s->values[s->len - 1] = s->values[s->len - 2];
	s->values[s->len - 2] = tmp;

instruction[0] = 's';
instruction[1] = s->name;
#ifdef DETAIL_INSTRUCTION
	if (s->name == 'a')
		print_stacks(s, NULL, instruction);
	else
		print_stacks(NULL, s, instruction);
#else
	ft_printf("%s\n", instruction);
#endif
}

/*
 * push the top element of a 'from' stack to the top of the 'dest' stack
 * @note Does nothing if from stack len == 0
 * @param from the stack which will lose the top element
 * @param dest the stack on which will be push
*/
void	push_stack(t_stack *from, t_stack *dest)
{
	char instruction[3];

	if (from->len == 0)
		return ;
	dest->len++;
	dest->values[dest->len - 1] = from->values[from->len - 1];
	from->values[from->len - 1] = 0;
	from->len--;

	instruction[0] = 'p';
	instruction[1] = dest->name;
#if DETAIL_INSTRUCTION
	if (dest->name == 'a')
		print_stacks(dest, from, instruction);
	else
		print_stacks(from, dest, instruction);
#else
	ft_printf("%s\n", instruction);
#endif
}

/*
 * rotate every element of a stack by one
 * @param s the stack to rotate
*/
void	rotate_stack(t_stack *s)
{
	int	top;
	int	i;
	char instruction[3];

	i = s->len;
	top = s->values[s->len-1];
	while (i > 0)
	{
		s->values[i] = s->values[i-1];
		i--;
	}
	s->values[0] = top;

	instruction[0] = 'r';
	instruction[1] = s->name;
#if DETAIL_INSTRUCTION
	if (s->name == 'a')
		print_stacks(s, NULL, instruction);
	else
		print_stacks(NULL, s, instruction);
#else
	ft_printf("%s\n", instruction);
#endif
}
/*
 * rotate every element of a stack by minus one
 * @param s the stack to rotate
*/
void	rrotate_stack(t_stack *s)
{
	int	tmp;
	int	i;
	char instruction[4];

	i = 0;
	while (i < s->len - 1)
	{
		tmp = s->values[i % (s->len)];
		s->values[i % s->len] = s->values[(i+1) % s->len];
		s->values[(i+1) % s->len] = tmp;
		i++;
	}

	instruction[0] = 'r';
	instruction[1] = 'r';
	instruction[2] = s->name;
	instruction[3] = 0;
#if DETAIL_INSTRUCTION
	if (s->name == 'a')
		print_stacks(s, NULL, instruction);
	else
		print_stacks(NULL, s, instruction);
#else
	ft_printf("%s\n", instruction);
#endif
}

