/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_declare_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 01:15:27 by yaboukir          #+#    #+#             */
/*   Updated: 2025/03/06 17:33:45 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	pre_init_program(t_program *prog, char **argv)
{
	prog->num_of_philos = ft_atoi(argv[1]);
	prog->num_of_eat = -1;
	if (argv[5])
		prog->num_of_eat = ft_atoi(argv[5]);
	sem_unlink("/philo_forks");
	sem_unlink("/philo_print");
	prog->forks = sem_open("/philo_forks", O_CREAT, 0644, prog->num_of_philos);
	prog->print_sem = sem_open("/philo_print", O_CREAT, 0644, 1);
}

void	init_program(t_program *prog, char **argv)
{
	int	i;

	pre_init_program(prog, argv);
	i = 0;
	while (i < prog->num_of_philos)
	{
		prog->philos[i].id = i + 1;
		prog->philos[i].num_of_philos = prog->num_of_philos;
		prog->philos[i].num_of_eat = prog->num_of_eat;
		prog->philos[i].time_to_die = ft_atoi(argv[2]);
		prog->philos[i].time_to_eat = ft_atoi(argv[3]);
		prog->philos[i].time_to_sleep = ft_atoi(argv[4]);
		prog->philos[i].start_clock = get_time();
		prog->philos[i].last_meal = get_time();
		prog->philos[i].meals_eaten = 0;
		prog->philos[i].forks = prog->forks;
		prog->philos[i].print_sem = prog->print_sem;
		i++;
	}
}

void	launch_processes(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->num_of_philos)
	{
		prog->philos[i].pid = fork();
		if (prog->philos[i].pid < 0)
		{
			write(2, "fork error\n", 12);
			exit(1);
		}
		if (prog->philos[i].pid == 0)
		{
			philosopher_routine(&prog->philos[i]);
			exit(0);
		}
		i++;
	}
}

void	kill_processes(t_program *prog)
{
	int	i;

	i = 0;
	while (i < prog->num_of_philos)
	{
		kill(prog->philos[i].pid, SIGKILL);
		i++;
	}
}
