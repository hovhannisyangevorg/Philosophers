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

	ft_get_time();
	if (ft_vuelidate(argc, argv))
		return (EXIT_FAILURE);
	if (ft_init_global(&global, argv))
		return (EXIT_FAILURE);
	ft_create_thread(&global);
	return (0);
}
