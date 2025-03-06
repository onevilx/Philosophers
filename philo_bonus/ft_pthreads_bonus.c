/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthreads_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:15:12 by yaboukir          #+#    #+#             */
/*   Updated: 2025/03/06 17:18:39 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*monitor_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if ((get_time() - philo->last_meal) > philo->time_to_die)
		{
			sem_wait(philo->print_sem);
			printf("%zu %d died\n", get_time() - philo->start_clock, philo->id);
			exit(1);
		}
		ft_delay(1);
	}
	return (NULL);
}

void	philosopher_routine(t_philo *philo)
{
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, monitor_routine, philo) != 0)
	{
		write(2, "pthread_create\n", 16);
		exit(1);
	}
	pthread_detach(monitor);
	while (philo->num_of_eat == -1 || philo->meals_eaten < philo->num_of_eat)
	{
		ft_eat(philo);
		ft_sleeping(philo);
		ft_think(philo);
	}
	exit(0);
}
