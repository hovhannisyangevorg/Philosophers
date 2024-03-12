/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:44:24 by gevorg            #+#    #+#             */
/*   Updated: 2024/03/06 15:49:35 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_time(void)
{
	static size_t				start;
	static int					call_count;
	struct timeval				t1;

	if (call_count == 0)
	{
		gettimeofday(&t1, NULL);
		start = (t1.tv_sec * 1000 + t1.tv_usec / 1000);
		call_count++;
	}
	gettimeofday(&t1, NULL);
	return ((t1.tv_sec * 1000) + (t1.tv_usec / 1000) - start);
}

void	ft_usleap(unsigned long t1)
{
	unsigned long	val;

	val = ft_get_time();
	while (ft_get_time() - val <= t1)
		usleep(50);
}