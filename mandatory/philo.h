/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onevilx <onevilx@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:28:03 by onevilx           #+#    #+#             */
/*   Updated: 2025/02/25 23:28:34 by onevilx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo
{
	int				id;
	int				eating;
	int				meals_eaten;
	int				num_of_philos;
	int				num_of_eat;
	int				*death;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_clock;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*death_lock;
	pthread_mutex_t	*meal_lock;
}				t_philo;

typedef struct s_program
{
	int				death_flag;
	t_philo			*philos;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}				t_program;

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		ft_delay(size_t milliseconds);
void	destory_pthread(char *str, t_program *program, pthread_mutex_t *forks);
size_t	get_time(void);

#endif
