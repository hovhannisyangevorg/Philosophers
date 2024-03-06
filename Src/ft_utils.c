/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:52:36 by gevorg            #+#    #+#             */
/*   Updated: 2024/03/01 19:17:19 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int vul)
{
	if (vul >= '0' && vul <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	const char	*ptr;

	ptr = str;
	while (ptr && *ptr)
		ptr++;
	return (ptr - str);
}

int	ft_panic(char *error)
{
	write (2, error, ft_strlen(error));
	write (2, "\n", 1);
	return (EXIT_FAILURE);
}
