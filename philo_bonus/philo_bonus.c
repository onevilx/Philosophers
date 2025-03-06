/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 00:58:58 by yaboukir          #+#    #+#             */
/*   Updated: 2025/03/06 03:55:50 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	valid_args(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_number(argv[1]))
		return (write(2, "Invalid Philosophers number\n", 29), 1);
	if (ft_atoi(argv[2]) <= 0 || check_number(argv[2]))
		return (write(2, "Invalid time to die\n", 21), 1);
	if (ft_atoi(argv[3]) <= 0 || check_number(argv[3]))
		return (write(2, "Invalid time to eat\n", 21), 1);
	if (ft_atoi(argv[4]) <= 0 || check_number(argv[4]))
		return (write(2, "Invalid time to sleep\n", 23), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_number(argv[5])))
		return (write(2, "Invalid Number each philosopher must eat\n", 42), 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_program	program;
	int			i;
	int			status;

	if (argc != 5 && argc != 6)
		return (write(2, "Invalid input!\n", 16), 1);
	if (valid_args(argv))
		return (1);
	init_program(&program, argv);
	launch_processes(&program);
	i = 0;
	while (i++ < program.num_of_philos)
	{
		waitpid(-1, &status, 0);
		if ((status >> 8) != 0)
		{
			kill_processes(&program);
			break ;
		}
	}
	sem_close(program.forks);
	sem_unlink("/philo_forks");
	sem_close(program.print_sem);
	sem_unlink("/philo_print");
	return (0);
}
