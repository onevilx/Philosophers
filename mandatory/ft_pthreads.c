/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthreads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:51:18 by yaboukir          #+#    #+#             */
/*   Updated: 2025/03/01 01:30:31 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->death_lock);
	if (*philo->death == 1)
		return (pthread_mutex_unlock(philo-> death_lock), 1);
	pthread_mutex_unlock(philo->death_lock);
	return (0);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_delay(1);
	while (!check_dead_loop(philo))
	{
		ft_eat(philo);
		ft_dream(philo);
		ft_think(philo);
	}
	return (ptr);
}

int	thread_create(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	watcher;
	int			i;

	if (pthread_create(&watcher, NULL, &waiter, program->philos) != 0)
		destory_pthread("Thread creation Error\n", program, forks);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[0] != 0))
			destory_pthread("Thread Creation Error\n", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(watcher, NULL) != 0)
		destory_pthread("Thread can't join\n", program, forks);
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destory_pthread("Thread can't join\n", program, forks);
		i++;
	}
	return (0);
}
