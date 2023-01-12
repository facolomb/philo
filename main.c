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

int	ft_all_philo_eat(t_arg *args)
{
	int		i;
	t_philo	philo;

	i = -1;
	if (args->philo[0].rules->to_eat == -1)
		return (0);
	while (++i < args->nb_philo)
	{
		philo = args->philo[i];
		if (philo.has_eat != philo.rules->to_eat)
			return (0);
	}
	return (1);
}

void	ft_wait_end(t_arg *args, pthread_t *threads)
{
	int		i;
	long	time;
	t_philo	philo;

	i = 0;
	while (1)
	{
		philo = args->philo[i];
		time = ft_time() - philo.last_eat;
		if (time > philo.rules->till_death)
		{
			pthread_mutex_lock(philo.print);
			printf("%ld %d died\n", ft_time(), philo.id);
			break ;
		}
		if (ft_all_philo_eat(args))
		{
			printf("All philo ate %d times\n", args->philo[0].rules->to_eat);
			break ;
		}
		i = (i + 1) % args->nb_philo;
		usleep(100);
	}
	ft_free(args, threads);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_eat = ft_time();
	if (philo->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print(ft_time(), philo, "took a fork");
		pthread_mutex_lock(philo->rigth_fork);
		ft_print(ft_time(), philo, "took a fork");
		ft_print(ft_time(), philo, "is eating");
		philo->last_eat = ft_time();
		ft_sleep(philo, 1);
		philo->has_eat++;
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->rigth_fork);
		if (philo->has_eat == philo->rules->to_eat)
			return (NULL);
		ft_print(ft_time(), philo, "is sleeping");
		ft_sleep(philo, 0);
		ft_print(ft_time(), philo, "is thinking");
	}
}

int	ft_philo(t_arg *args, pthread_t *threads)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < args->nb_philo)
	{
		ret = pthread_create(&threads[i], NULL, ft_routine, args->philo + i);
		if (ret != 0)
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t	*threads;
	t_arg		*args;
	t_rules		rules;

	if (argc > 4 && argc <= 6)
	{
		if (!ft_check_argv(argc, argv))
			return (1);
		ft_time();
		args = malloc(sizeof(t_arg));
		if (ft_atoi_argv(&rules, args, argc, argv) != 0)
			return (2);
		threads = malloc(sizeof(pthread_t) * args->nb_philo);
		if (ft_philo(args, threads) != 0)
			return (3);
		ft_wait_end(args, threads);
	}
	else
		printf("Wrong number of arguments\n");
	return (0);
}
