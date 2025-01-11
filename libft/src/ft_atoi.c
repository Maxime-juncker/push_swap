/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuncker <mjuncker@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:28:20 by mjuncker          #+#    #+#             */
/*   Updated: 2025/01/11 13:04:56 by mjuncker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(long n, int sign)
{
	if (n * 10 / 10 != n)
	{
		if (sign < 0)
			return (0);
		return (-1);
	}
	return (2);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (check_overflow(n, sign) != 2)
			return (check_overflow(n, sign));
		n *= 10;
		n += nptr[i] - '0';
		i++;
	}
	n *= sign;
	return ((int)n);
}

int overflow_check(const char* s, void(*f)(int, void*), void *param)
{
    int result;
    int sign;
    int i;

    i = 0;
    result = 0;
    sign = 1;
    while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
        i++;
    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
            sign = -1;
        i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		if (result > MAX_INT / 10)
			return (f(MAX_INT, param), MAX_INT);
		if (result < MIN_INT / 10)
			return (f(MIN_INT, param), MIN_INT);
		result *= 10;
		if (result > MAX_INT - (s[i] - '0'))
			return (f(MAX_INT, param), MAX_INT);
		if (result < MIN_INT + (s[i] - '0'))
			return (f(MIN_INT, param), MIN_INT);
		if (sign < 0)
			result -= s[i] - '0';
		else
			result += s[i] - '0';
		i++;
	}
	return (result);
}
