/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:41:50 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/08 13:28:02 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	error_exit(t_list *a)
{
	if (a != NULL)
		ft_lstclear(&a, &free);
	ft_putstr_fd("\033[31mError\n\033[0m", STDERR_FILENO);
	exit (1);
}

static void	cleanup(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	check_errors(t_list *a)
{
	t_list	*cpy;
	int		tmp;
	int		i;

	while (a)
	{
		tmp = ft_atoi(a->content);
		i = 0;
		while (((char *)a->content)[i])
		{
			if (ft_isdigit(((char *)a->content)[i]) == 0)
				return (1);
			i++;
		}
		cpy = a->next;
		while (cpy)
		{
			if (cpy->content == NULL || ft_atoi(cpy->content) == tmp)
				return (1);
			cpy = cpy->next;
		}
		a = a->next;
	}
	return (0);
}

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
		error_exit(NULL);
	if (count == 1)
	{
		tmp = ft_split(*values, ' ');
		if (tmp == NULL)
			exit(1);
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
