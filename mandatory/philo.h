/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:54:33 by yaboukir          #+#    #+#             */
/*   Updated: 2025/03/01 02:08:11 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

#define PHILO_MAX 200

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
int		valid_args(char	**argv);
int		check_number(char *str);
int		ft_delay(size_t milliseconds);
int		check_dead_loop(t_philo *philo);
int		check_if_all_ate(t_philo *philos);
int		check_if_any_dead(t_philo *philos);
int		check_philo_dead(t_philo *philo, size_t time_to_die);
int		thread_create(t_program *program, pthread_mutex_t *forks);
void	*waiter(void *ptr);
void	ft_eat(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_dream(t_philo *philo);
void	*philo_routine(void *ptr);
void	ft_message(char *str, t_philo *philo, int id);
void	initialize_input(t_philo *philo, char **argv);
void	start_forks(pthread_mutex_t	*forks, int	philos);
void	start_program(t_program	*program, t_philo *philos);
void	destory_pthread(char *str, t_program *program, pthread_mutex_t *forks);
void	start_philos(t_philo *philos, t_program *program, pthread_mutex_t *forks, char **argv);
size_t	get_time(void);

#endif
