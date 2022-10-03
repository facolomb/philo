/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:06:03 by facolomb          #+#    #+#             */
/*   Updated: 2022/09/29 14:06:03 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo.h"

void	ft_free(t_arg *args, pthread_t *threads)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < args->nb_philo)
	{
		ret = pthread_mutex_destroy(&args->forks[i]);
		if (ret != 0)
			exit (1);
	}
	ret = pthread_mutex_destroy(&args->pr);
	if (ret != 0)
		exit (1);
	free(args->philo);
	free(args->forks);
	free(args);
	free(threads);
}
