/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:58:37 by yaboukir          #+#    #+#             */
/*   Updated: 2025/03/06 03:46:55 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_message(char *str, t_philo *philo)
{
	sem_wait(philo->print_sem);
	printf("%zu %d %s\n", get_time() - philo->start_clock, philo->id, str);
	sem_post(philo->print_sem);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->forks);
	ft_message("has taken a fork", philo);
	sem_wait(philo->forks);
	ft_message("has taken a fork", philo);
	ft_message("is eating", philo);
	philo->last_meal = get_time();
	ft_delay(philo->time_to_eat);
	philo->meals_eaten++;
	sem_post(philo->forks);
	sem_post(philo->forks);
}

void	ft_sleeping(t_philo *philo)
{
	ft_message("is sleeping", philo);
	ft_delay(philo->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_message("is thinking", philo);
}
