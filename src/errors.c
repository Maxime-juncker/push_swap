/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:16:57 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/13 10:18:20 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	error_exit(t_list *a)
{
	if (a != NULL)
		ft_lstclear(&a, &free);
	ft_putstr_fd("\033[31mError\n\033[0m", STDERR_FILENO);
	exit (1);
}

static void	overflow_error(int n, void *param)
{
	(void)n;
	error_exit((t_list *)param);
}

void	cleanup(char **arr)
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

int	check_errors(t_list *a)
{
	t_list	*cpy;
	int		tmp;
	int		i;

	while (a)
	{
		tmp = overflow_check(a->content, &overflow_error, (void *)a);
		i = -1;
		while (((char *)a->content)[++i])
		{
			if (ft_isdigit(((char *)a->content)[i]) == 0 && \
			!(i == 0 && ((char *)a->content)[i] == '-' && \
			ft_strlen((char *)a->content) > 1))
				return (1);
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
