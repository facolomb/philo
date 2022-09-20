/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:12:11 by facolomb          #+#    #+#             */
/*   Updated: 2022/09/20 10:12:11 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(void)
{
	struct timeval time;
	t_arg	arg;
	long 	time_start;

	arg.philo = malloc(sizeof(t_philo));
	gettimeofday(&time, NULL);
	time_start = time.tv_sec;
	arg.philo->last_eat = time.tv_sec;
	arg.sleep = 2;
	arg.till_death = 2;
	printf("last_eat : %ld\n", arg.philo->last_eat);
	printf("sleeping...\n");
	sleep(arg.sleep);
	gettimeofday(&time, NULL);
	if (time_start + arg.till_death == time.tv_sec)
		printf("death\n");
	free(arg.philo);
	return (0);
}
