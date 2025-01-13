/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:41:50 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/13 10:17:07 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static t_list	*create_stack(int count, char **values)
{
	t_list	*a;
	t_list	*new;
	int		i;

	a = NULL;
	i = 0;
	while (i < count)
	{
		new = ft_lstnew(ft_strdup(values[i]));
		if (new == NULL || new->content == NULL)
			error_exit(a);
		ft_lstadd_back(&a, new);
		i++;
	}
	return (a);
}

t_list	*build_stack(int count, char **values)
{
	char	**tmp;
	int		i;
	t_list	*a;

	if (count == 0)
		exit(0);
	if (count == 1)
	{
		tmp = ft_split(*values, ' ');
		if (tmp == NULL)
			error_exit(NULL);
		i = 0;
		while (tmp[i])
			i++;
		a = create_stack(i, tmp);
		cleanup(tmp);
	}
	else
		a = create_stack(count, values);
	if (check_errors(a) == 1)
		error_exit(a);
	return (a);
}
