/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:45:32 by facolomb          #+#    #+#             */
/*   Updated: 2022/09/20 15:45:32 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_fork(t_arg *args, int nb_philo)
{
	int i;

	i = 1;
	args->forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	args->philo[0].left_fork = &args->forks[0];
	args->philo[0].rigth_fork = &args->forks[nb_philo - 1];
	printf("philo %d : fork 0 && %d\n", args->philo[0].id, nb_philo - 1);
	while (i < nb_philo)
	{
		args->philo[i].left_fork = &args->forks[i];
		args->philo[i].rigth_fork = &args->forks[i - 1];
		printf("philo %d : fork %d && %d\n", args->philo[i].id, i, i - 1);
		i++;
	}
	while (i >= 0)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		i--;
	}
}

void	ft_init_philo(t_philo *philo, int nb_philo)
{
	int i;

	i = 0;
	while (i < nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].has_eat = 0;
		i++;
	}
}

void	ft_init_arg(t_arg *args, int nb)
{
	args->philo = malloc(sizeof(t_philo) * nb);
	ft_init_philo(args->philo, nb);
	ft_init_fork(args, nb);
}