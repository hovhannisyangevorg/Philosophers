#include "philo.h"

void	ft_free_philo(t_global *global)
{
	size_t i;

	i = -1;
	while (i < global->count_philo)
	{
		pthread_mutex_destroy(&(global->philo[i].last_eat_mutex));
		pthread_mutex_destroy(&(global->philo[i].each_eat));
	}
	free(global->philo);
}

void	ft_free_global(t_global *global)
{
	size_t i;

	i = -1;
	pthread_mutex_destroy(&(global->mutex_write));
	pthread_mutex_destroy(&(global->mutex_die));
	while (++i < global->count_philo)
	{
		pthread_mutex_destroy(&(global->mutex[i]));
	}
	free(global->mutex);
}
