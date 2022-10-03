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

void	ft_init_fork(t_arg *args)
{
	int	i;
	int	ret;

	i = 1;
	args->forks = malloc(sizeof(pthread_mutex_t) * args->nb_philo);
	args->philo[0].left_fork = &args->forks[0];
	args->philo[0].rigth_fork = &args->forks[args->nb_philo - 1];
	while (i < args->nb_philo)
	{
		args->philo[i].left_fork = &args->forks[i];
		args->philo[i].rigth_fork = &args->forks[i - 1];
		i++;
	}
	while (i >= 0)
	{
		ret = pthread_mutex_init(&args->forks[i], NULL);
		if (ret != 0)
			exit (1);
		i--;
	}
}

void	ft_init_philo(t_philo *philo, t_rules *rules, t_arg args)
{
	int	i;

	i = 0;
	while (i < args.nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].has_eat = 0;
		philo[i].last_eat = 0;
		philo[i].rules = rules;
		philo[i].print = &args.pr;
		i++;
	}
}

void	ft_init_arg(t_arg *args, t_rules *rules)
{
	pthread_mutex_init(&args->pr, NULL);
	args->philo = malloc(sizeof(t_philo) * args->nb_philo);
	ft_init_philo(args->philo, rules, *args);
	ft_init_fork(args);
}

void	ft_atoi_argv(t_rules *rules, t_arg *args, int nb_arg, char **arg)
{
	args->nb_philo = ft_atoi(arg[1]);
	rules->till_death = ft_atoi(arg[2]);
	rules->time_eat = ft_atoi(arg[3]);
	rules->sleep = ft_atoi(arg[4]);
	if (nb_arg == 6)
		rules->to_eat = ft_atoi(arg[5]);
	else
		rules->to_eat = -1;
	ft_init_arg(args, rules);
}

int	ft_check_argv(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_isalldigit(argv[i]) == 0)
		{
			printf("Wrong types of arguments\n");
			return (0);
		}
	}
	return (1);
}
