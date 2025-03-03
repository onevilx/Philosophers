/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declare_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:51:35 by yaboukir          #+#    #+#             */
/*   Updated: 2025/03/03 04:06:22 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	initialize_input(t_philo *philo, char **argv)
{
	philo->num_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->num_of_eat = ft_atoi(argv[5]);
	else
		philo->num_of_eat = -1;
}

void	start_program(t_program	*program, t_philo *philos)
{
	program->death_flag = 0;
	program->philos = philos;
	pthread_mutex_init(&program->write_lock, NULL);
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
}

void	start_forks(pthread_mutex_t *forks, int philos)
{
	int	i;

	i = 0;
	while (i < philos)
		pthread_mutex_init(&forks[i++], NULL);
}

void	start_philos(t_philo *philos, t_program *program,
			pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		initialize_input(&philos[i], argv);
		philos[i].start_clock = get_time();
		philos[i].last_meal = get_time();
		philos[i].write_lock = &program->write_lock;
		philos[i].death_lock = &program->dead_lock;
		philos[i].meal_lock = &program->meal_lock;
		philos[i].death = &program->death_flag;
		philos[i].left_fork = &forks[i];
		if (i == 0)
			philos[i].right_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].right_fork = &forks[i - 1];
		i++;
	}
}
