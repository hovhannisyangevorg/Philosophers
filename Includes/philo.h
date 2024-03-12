/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:19:36 by gevorg            #+#    #+#             */
/*   Updated: 2024/03/01 18:12:55 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <stdint.h>
# include <stddef.h>
# include <limits.h>

# include "philo_struct.h"

/**
 * Philo/Src/ft_philo_utils.c
 */
size_t		ft_strlen(const char *str);
int			ft_panic(char *error);
int			ft_isdigit(int vul);

/**
 * Philo/Src/ft_atoll.c
 */
size_t	ft_atos(char *str, int *is_overflowed);
int		ft_isadd_overflow_s(size_t a, size_t b);
int		ft_ismultiply_overflow_s(size_t a, size_t b);
int		ft_isspace(int arg);


/**
 * Philo/Src/ft_vuelidate.c
 */
int	ft_vuelidate(int argc, char **argv);



int             ft_is_dead(char **argv);
void	        ft_init_args(t_global *global, t_info *philo, char **argv, size_t index);
t_info          *ft_init_philo(t_global *global, char **argv);
pthread_mutex_t	*ft_init_fork(t_global *global);
void            ft_init_global(t_global *global, char **argv);

#endif