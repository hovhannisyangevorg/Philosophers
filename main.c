/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:57:47 by gevorg            #+#    #+#             */
/*   Updated: 2024/02/21 18:39:35 by gevorg           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <stdint.h>
# include <stddef.h>
# include <limits.h>


typedef struct main
{
	int 			namber;
	pthread_mutex_t	each_eat;
} t_main;


void *f(void *main)
{
	t_main *main_d = (t_main*)main;

	pthread_mutex_lock(&main_d->each_eat);
	printf("%d\n", ++main_d->namber);
	pthread_mutex_unlock(&main_d->each_eat);


	return (NULL);	
}

int main()
{
	pthread_t		philo;
	t_main main;

	main.namber = 0;
	pthread_mutex_init(&main.each_eat, NULL);

	pthread_create(&philo, NULL, &f, &main);

	pthread_mutex_lock(&main.each_eat);
	printf("%d\n", ++main.namber);
	pthread_mutex_unlock(&main.each_eat);
	
	pthread_join(philo, NULL);

	// 	while (1)
	// {
	// }

	
	return 0;
}
