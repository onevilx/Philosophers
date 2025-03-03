/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:51:42 by yaboukir          #+#    #+#             */
/*   Updated: 2025/03/03 04:11:32 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_think(t_philo *philo)
{
	ft_message("is thinking", philo, philo->id);
}

void	ft_dream(t_philo *philo)
{
	ft_message("is sleeping", philo, philo->id);
	ft_delay(philo->time_to_sleep);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ft_message("has taken a fork", philo, philo->id);
	if (philo->num_of_philos == 1)
	{
		ft_delay(philo->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	ft_message("has taken a fork", philo, philo->id);
	philo->eating = 1;
	ft_message("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_delay(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
