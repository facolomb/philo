/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:41:26 by facolomb          #+#    #+#             */
/*   Updated: 2022/07/11 14:41:26 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	*thread_test(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("Thread : %d start execution\n", philo->id);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->rigth_fork);
	printf("Philo %d took forks\n", philo->id);
	printf("Philo %d has eat\n", philo->id);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->rigth_fork);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int i;
	pthread_t *threads;
	t_arg *args;

	if (argc > 4)
	{
		i = 0;
		args = malloc(sizeof(t_arg));
		ft_atoi_args(args, argc, argv);
		threads = malloc(sizeof(pthread_t) * 4);
		while (i < 6)
		{
			pthread_create(&threads[i], NULL, thread_test, args->philo + i);
			i++;
		}
		usleep(100);
		i = 0;
		while (i < 6)
		{
			pthread_mutex_destroy(&args->forks[i]);
			i++;
		}
		free(args->philo);
		free(args->forks);
		free(args);
		free(threads);
	}
	return (0);
}
