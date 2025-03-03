/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:50:53 by yaboukir          #+#    #+#             */
/*   Updated: 2025/03/03 00:14:57 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_number(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	valid_args(char	**argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_number(argv[1]) == 1)
		return (write(2, "Invalid Philosophers number\n", 29), 1);
	if (ft_atoi(argv[2]) <= 0 || check_number(argv[2]) == 1)
		return (write(2, "Invalid time to die\n", 21), 1);
	if (ft_atoi(argv[3]) <= 0 || check_number(argv[3]) == 1)
		return (write(2, "Invalid time to eat\n", 21), 1);
	if (ft_atoi(argv[4]) <= 0 || check_number(argv[4]) == 1)
		return (write(2, "Invalid time to sleep\n", 23), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_number(argv[5]) == 1))
		return (write(2, "Invalid Number each philosopher must eat", 41), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		return (write(2, "Invalid input!", 15), 1);
	if (valid_args(argv) == 1)
		return (1);
	start_program(&program, philos);
	start_forks(forks, ft_atoi(argv[1]));
	start_philos(philos, &program, forks, argv);
	thread_create(&program, forks);
	destory_pthread(NULL, &program, forks);
	return (0);
}
