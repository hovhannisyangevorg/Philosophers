/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:19:38 by gevorg            #+#    #+#             */
/*   Updated: 2024/03/06 15:51:22 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <limits.h>

#define MAX 6
#define MIN 5

typedef struct 	s_global	t_global;
typedef struct	s_input	t_input;

typedef void*	(*t_thread_handler)(void*);

typedef struct s_info
{
	size_t			last_eat; //-
	int				*is_dead;
	int				id;
	int				date_of_eat;
	int				date_of_sleep;
	int				count_each_eat;
	pthread_t		philo;
	pthread_mutex_t	last_eat_mutex;
	pthread_mutex_t	each_eat;
	pthread_mutex_t	*mutex_die;
	pthread_mutex_t	*mutex_write;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

}		t_info;

typedef struct s_global
{
	size_t			time_to_die; //-
	int				count_philo;
	int				max_eat;
	int				is_dead;
	t_info			*philo;
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	mutex_die;
	pthread_mutex_t	*mutex;
}		t_global;

#endif