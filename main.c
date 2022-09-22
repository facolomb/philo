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

void	*timer(void *arg)
{
	t_arg	*args;
	t_philo	philo;
	struct timeval time;
	int 	i;

	args = (t_arg *)arg;
	while (1)
	{
		i = 0;
		while (i < args->nb_philo)
		{
			philo = args->philo[i];
			gettimeofday(&time, NULL);
			if (time.tv_usec - philo.last_eat < philo.rules->till_death)
				; //TO DO Death
		}
	}
	return (NULL);
}

void	*thread_test(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Thread : %d start execution\n", philo->id);
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->rigth_fork);
		printf("Philo %d took forks\n", philo->id);
		printf("Philo %d is eating\n", philo->id);
		usleep(philo->rules->to_eat);
		philo->has_eat++;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->rigth_fork);
		printf("Philo %d is sleeping\n", philo->id);
		usleep(philo->rules->sleep);
		printf("Philo %d is thinking\n", philo->id);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	int 		i;
	pthread_t	*threads;
	pthread_t 	thread_timer;
	t_arg		*args;
	t_rules		rules;

	if (argc > 4)
	{
		i = 0;
		args = malloc(sizeof(t_arg));
		ft_atoi_argv(&rules, args, argc, argv);
		threads = malloc(sizeof(pthread_t) * 4);
		while (i < args->nb_philo)
		{
			pthread_create(&threads[i], NULL, thread_test, args->philo + i);
			i++;
		}
		pthread_create(&thread_timer, NULL, timer, args);
		i = 0;
		while (i < args->nb_philo)
		{
			pthread_join(threads[i], NULL);
			i++;
		}
		i = 0;
		while (i < args->nb_philo)
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
