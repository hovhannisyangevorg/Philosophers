/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:54:55 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/20 18:17:49 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isspace(int arg)
{
	return (arg == 32 || (arg >= 9 && arg <= 13));
}

int ft_ismultiply_overflow_s(size_t a, size_t b)
{
	if (a == 0 || b == 0)
		return 0;
	if (a > SIZE_MAX / b)
		return (1);
	return (0);
}

int ft_isadd_overflow_s(size_t a, size_t b)
{
	if (a > SIZE_MAX - b)
		return (1);
	return (0);
}

size_t ft_atos(char* str, int* is_overflowed)
{
	size_t	i;
	size_t	res;
	size_t	tmp;

	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			*is_overflowed = 1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (ft_ismultiply_overflow_s(res, 10))
			*is_overflowed = 1;
		tmp = res * 10;
		if (ft_isadd_overflow_s(tmp, str[i] - '0'))
			*is_overflowed = 1;
		res = tmp + (str[i] - '0');
		++i;
	}
	return (res);
}
