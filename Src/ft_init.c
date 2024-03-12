/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:42:48 by gevorg            #+#    #+#             */
/*   Updated: 2024/03/01 18:13:01 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_have_last(char **argv)
{
	int isower;

	isower = 0;
	if (argv[5])
		return (ft_atos(argv[5], &isower));
	else
		return (-1);
}

void	ft_init_args(t_global *global, t_info *philo, char **argv, size_t index)
{
	int isower;

	isower = 0;
	philo->last_eat = 0;
	philo->is_dead = &global->is_dead;
	philo->id = index;
	philo->date_of_eat = ft_atos(argv[3], &isower);
	philo->date_of_sleep = ft_atos(argv[4], &isower);
	philo->count_each_eat = 0;
	pthread_mutex_init(&philo->last_eat_mutex, NULL);
	pthread_mutex_init(&philo->each_eat, NULL);
	philo->mutex_die = &(global->mutex_die);
	philo->mutex_write = &(global->mutex_write);
}

t_info	*ft_init_philo(t_global *global, char **argv)
{
	size_t i;
	t_info	*philo;

	i = -1;
	philo = malloc(sizeof(t_info) * global->count_philo);
	if (!philo)
		return (NULL);
	while (++i < global->count_philo)
		ft_init_args(global, &philo[i], argv, i + 1);
	return (philo);
}

void	ft_init_mutex(t_global *global, pthread_mutex_t *mutex)
{
	size_t i;

	i = -1;
	while (++i < global->count_philo)
		pthread_mutex_init(&mutex[i], NULL);
}

pthread_mutex_t	*ft_init_fork(t_global *global)
{
	size_t i;
	t_info *philo;
	pthread_mutex_t	*mutex;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * global->count_philo);
	if (!mutex)
		return (NULL);
	ft_init_mutex(global, mutex);
	i = -1;
	philo = global->philo;
	while (++i < global->count_philo)
	{
		if (i == (global->count_philo - 1))
		{
			philo[i].left = &mutex[i];
			philo[i].right = &mutex[0];
		} 
		philo[i].left = &mutex[i];
		philo[i].right = &mutex[i + 1];
	}
	return (mutex);
}

int ft_init_global(t_global *global, char **argv)
{
	int isower;

	isower = 0;
	global->time_to_die = ft_atos(argv[2], &isower);
	global->count_philo = ft_atos(argv[1], &isower);
	global->max_eat = ft_have_last(argv);
	global->is_dead = 0;
	pthread_mutex_init(&(global->mutex_write), NULL);
	pthread_mutex_init(&(global->mutex_die), NULL);
	global->philo = ft_init_philo(global, argv);
	global->mutex = ft_init_fork(global);
    if (!global->philo || !global->mutex)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
