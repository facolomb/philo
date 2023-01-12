/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:16:18 by facolomb          #+#    #+#             */
/*   Updated: 2022/09/28 15:16:18 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_rules
{
	int	till_death;
	int	time_eat;
	int	sleep;
	int	to_eat;
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				has_eat;
	long			last_eat;
	pthread_mutex_t	*rigth_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*print;
	t_rules			*rules;
}	t_philo;

typedef struct s_arg
{
	t_philo			*philo;
	pthread_mutex_t	pr;
	int				nb_philo;
	pthread_mutex_t	*forks;
}	t_arg;

// -- Init -- //
int		ft_atoi_argv(t_rules *rules, t_arg *args, int nb_arg, char **arg);
int		ft_check_argv(int argc, char **argv);
// -- Timer -- //
long	ft_time(void);
void	ft_sleep(t_philo *philo, int is_eat);
// -- Utils -- //
int		ft_atoi(const char *str);
int		ft_isalldigit(const char *str);
void	ft_print(unsigned long time, t_philo *philo, char *str);
void	ft_free(t_arg *args, pthread_t *threads);
#endif
