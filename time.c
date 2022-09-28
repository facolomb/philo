/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:48:34 by facolomb          #+#    #+#             */
/*   Updated: 2022/09/28 14:48:34 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

long	ft_get_time(void)
{
	struct timeval	timer;
	long			s;
	long			us;

	gettimeofday(&timer, NULL);
	s = timer.tv_sec * 1000;
	us = timer.tv_usec / 1000;
	return (s + us);
}

long	ft_time(void)
{
	static long	time;

	if (time == 0)
		time = ft_get_time();
	return (ft_get_time() - time);
}

void	ft_sleep(t_philo *philo, int is_eat)
{
	long	time;
	int		sleep;

	time = ft_time();
	if (is_eat == 1)
		sleep = philo->rules->time_eat;
	else
		sleep = philo->rules->sleep;
	while (ft_time() - time < sleep)
		usleep(100);
}
