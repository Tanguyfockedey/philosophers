/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:03:59 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/18 19:42:43 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_rules(char **argv, t_rules *rules)
{
	rules->nb_philo = ft_atoi(argv[1]);
	rules->time_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rules->nb_eat = ft_atoi(argv[5]);
	else
		rules->nb_eat = __INT_MAX__;
	if (rules->nb_philo < 1 || rules->time_die <= 0 || rules->time_eat <= 0
		|| rules->time_sleep <= 0 || rules->nb_eat <= 0)
	{
		printf("Wrong argument values !\n");
		return (1);
	}
	rules->philo = malloc(rules->nb_philo * sizeof(t_philosopher));
	if (!rules->philo)
		return (12);
	rules->fork = malloc(rules->nb_philo * sizeof(pthread_mutex_t));
	if (!rules->fork)
	{
		free(rules->philo);
		rules->philo = NULL;
		return (12);
	}
	return (0);
}

static int	init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		rules->philo[i].nb_meals = 0;
		rules->philo[i].time_last_meal = 0;
		i++;
	}
	return (0);
}

static int	init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_mutex_init(&(rules->fork[i]), NULL);
		i++;
	}
	return (0);
}

int	ft_init(char **argv, t_rules *rules)
{
	int	err;

	if ((err = init_rules(argv, rules)))
		return (err);
	if ((err = init_philo(rules)))
		return (err);
	if ((err = init_mutex(rules)))
		return (err);
	return (0);
}
