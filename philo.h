
#ifndef PHILO_PHILO_H
#define PHILO_PHILO_H
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_rules
{
	int till_death;
	int time_eat;
	int sleep;
	int to_eat;
}	t_rules;

typedef struct s_philo
{
	int id;
	int has_eat;
	long last_eat;
	pthread_mutex_t *rigth_fork;
	pthread_mutex_t *left_fork;
	t_rules	*rules;
}	t_philo;

typedef struct s_arg
{
	t_philo	*philo;
	int nb_philo;
	pthread_mutex_t	*forks;
}	t_arg;

int		ft_atoi(const char *str);
void	ft_atoi_argv(t_rules *rules, t_arg *args, int nb_arg, char **arg);
void	ft_init_arg(t_arg *args, t_rules *rules);
void	ft_init_philo(t_philo *philo, t_rules *rules, int nb_philo);
void	ft_init_fork(t_arg *args);
#endif
