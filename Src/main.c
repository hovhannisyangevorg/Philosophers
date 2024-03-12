/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:18:11 by gevorg            #+#    #+#             */
/*   Updated: 2024/03/01 19:13:52 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"




int main(int argc, char **argv)
{
	t_global global;

	if (ft_vuelidate(argc, argv))
		return (EXIT_FAILURE);
	ft_init_global(&global, argv);
	if (!global.philo || !global.mutex)
		return (EXIT_FAILURE);
	
	
	return (0);
}
