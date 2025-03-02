/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:51:01 by yaboukir          #+#    #+#             */
/*   Updated: 2025/03/02 03:40:12 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->start_clock;
	if (!check_dead_loop(philo))
		printf("%zu %d %s \n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	check_philo_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_time() - philo->last_meal >= time_to_die && philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	check_if_any_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (check_philo_dead(&philos[i], philos[i].time_to_die))
		{
			ft_message("Died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[0].death_lock);
			*philos->death = 1;
			pthread_mutex_unlock(philos[0].death_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_if_all_ate(t_philo *philos)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	if (philos[0].num_of_eat == -1)
		return (0);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_of_eat)
			finished++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finished == philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[0].death_lock);
		*philos->death = 1;
		pthread_mutex_unlock(philos[0].death_lock);
		return (1);
	}
	return (0);
}

void	*waiter(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
		if (check_if_any_dead(philos) == 1 || check_if_all_ate(philos) == 1)
			break ;
	return (ptr);
}
