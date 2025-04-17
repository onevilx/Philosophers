/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:14:51 by yaboukir          #+#    #+#             */
/*   Updated: 2025/04/17 23:33:13 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/wait.h>
# include <signal.h>
# include <fcntl.h>

# define PHILO_MAX 200

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	int				num_of_philos;
	int				num_of_eat;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			last_meal;
	size_t			start_clock;
	pid_t			pid;
	sem_t			*forks;
	sem_t			*limit;
	sem_t			*print_sem;
}				t_philo;

typedef struct s_program
{
	int				num_of_philos;
	int				num_of_eat;
	t_philo			philos[PHILO_MAX];
	sem_t			*forks;
	sem_t			*limit;
	sem_t			*print_sem;
}				t_program;

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		check_number(char *str);
int		valid_args(char **argv);
int		ft_delay(size_t milliseconds);
void	ft_eat(t_philo *philo);
void	ft_think(t_philo *philo);
void	ft_sleeping(t_philo *philo);
void	kill_processes(t_program *prog);
void	launch_processes(t_program *prog);
void	philosopher_routine(t_philo *philo);
void	ft_message(char *str, t_philo *philo);
void	init_program(t_program *prog, char **argv);
void	pre_init_program(t_program *prog, char **argv);
size_t	get_time(void);

#endif
