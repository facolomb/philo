/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:33:25 by facolomb          #+#    #+#             */
/*   Updated: 2022/09/20 15:33:25 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*ft_trim(const char *str)
{
	char	*ret;

	while (*str == ' ' || *str == '\t'
		   || *str == '\v' || *str == '\f'
		   || *str == '\r' || *str == '\n')
	{
		str++;
	}
	ret = (char *)str;
	return (ret);
}

static int	ft_sign(const char *str)
{
	int	sign;

	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int		res;
	int		i;
	int		sign;
	char	*trimed;

	res = 0;
	i = 0;
	trimed = ft_trim(str);
	sign = ft_sign(trimed);
	if (trimed[i] == '-' || trimed[i] == '+')
		i++;
	while (trimed[i] >= '0' && trimed[i] <= '9')
	{
		res = res * 10 + trimed[i] - '0';
		i++;
	}
	return (res * sign);
}
