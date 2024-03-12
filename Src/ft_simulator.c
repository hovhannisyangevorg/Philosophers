#include "philo.h"

int	ft_set_dead(t_info *philo)
{
	int isdead;

	isdead = 0;
	pthread_mutex_lock(philo->mutex_die);
	isdead = *(philo->is_dead);
	pthread_mutex_unlock(philo->mutex_die);
	return (isdead);
}

void	ft_lockprintf(t_info *philo, char *messg)
{
	pthread_mutex_lock(philo->mutex_write);
	if (!ft_set_dead(philo))
		printf("%d, %zu, %s\n", philo->id, ft_get_time(), messg);
	pthread_mutex_unlock(philo->mutex_write);
}

void	*ft_handler_simulator(t_info *philo)
{
	if ((philo->id % 2) != 0)
		ft_usleap(philo->date_of_eat);

	while (!ft_set_dead(philo))
	{
		pthread_mutex_lock(philo->left);
		ft_lockprintf(philo, TAKEN_LEFT);
		pthread_mutex_lock(philo->right);
		ft_lockprintf(philo, TAKEN_RIGHT);
		ft_lockprintf(philo, EAT_NOW);
		pthread_mutex_lock(philo->last_eat);
		philo->last_eat = ft_get_time();
		pthread_mutex_unlock(philo->last_eat);
		ft_usleap(philo->date_of_eat);
		pthread_mutex_lock(&philo->each_eat);
		++(philo->count_each_eat);
		pthread_mutex_nulock(&philo->each_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		ft_lockprintf(philo, SLEEP);
		ft_usleap(philo->date_of_sleep);
		ft_lockprintf(philo, THINK);
	}
	return (NULL);
}

int ft_is_philo_dead(t_global *global)
{
    size_t i;
    t_info *philo;

    i = -1;
    philo = global->philo;
    while (++i < global->count_philo)
    {
        pthread_mutex_lock(philo[i].last_eat);
        if ((ft_get_time() - philo[i].last_eat) > global->time_to_die)
        {
            pthread_mutex_lock(&(global->mutex_die));
            global->is_dead = 1;
            pthread_mutex_unlock(&(global->mutex_die));
            pthread_mutex_lock(&(global->mutex_write));
            printf("%d %zu %s\n", philo->id, (ft_get_time() - philo->last_eat), IS_DEAD);
            pthread_mutex_unlock(&(global->mutex_write));
            pthread_mutex_unlock(philo[i].last_eat);
            return (EXIT_FAILURE);
        }
        pthread_mutex_unlock(philo[i].last_eat);
    }
    return (EXIT_SUCCESS);
}

int	ft_iseat(t_global *global)
{
	
}

void	ft_create_thread(t_global *global)
{
	size_t i;
	t_info *philo;

	i = -1;
	philo = global->philo;
	while (++i < global->count_philo)
		pthread_create(&(philo[i].philo), NULL, (t_thread_handler)(&ft_handler_simulator), &philo[i]);
	while (TRUE)
	{
		if (ft_is_philo_dead(global) || ft_iseat(global))
			break ;

	}
}
