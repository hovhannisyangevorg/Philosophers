/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vuelidate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:57:32 by gevorg            #+#    #+#             */
/*   Updated: 2024/03/01 19:13:15 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isnumber(char *args)
{
	int i;

	i = -1;
	if (*args == '\0')
		return (ft_panic("Error: Invalid argument - Value empty."));
	while (args && args[++i])
	{	
		if (!ft_isdigit(args[i]))
			return (ft_panic("Error: Invalid argument - Value must be number."));
	}
	return (EXIT_SUCCESS);
}

int	ft_isvulid(char *args)
{
	int			is_overflowed;

	is_overflowed = 0;
	ft_atos(args, &is_overflowed);
	if (is_overflowed)
		return (ft_panic("Error: Invalid argument - Value must be within the range of the minimum size_t value to the maximum size_t value."));
	return (EXIT_SUCCESS);
}

int	ft_vuelidate(int argc, char **argv)
{
	size_t	i;

	i = 0;
	if (argc == MIN || argc == MAX)
	{
		while (argv && argv[++i])
			if (ft_isnumber(argv[i]) || ft_isvulid(argv[i]))
				return (EXIT_FAILURE);
	}
	else
		return (ft_panic("Error: Invalid argument - Value count must be 4 or 5."));
	return (EXIT_SUCCESS);
}
