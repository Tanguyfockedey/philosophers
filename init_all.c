/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:03:59 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/25 21:07:12 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	init_rules(char **argv, t_rules *rules)
{
	rules->nb_philo = atoi(argv[1]);
	rules->time_die = atoi(argv[2]);
	rules->time_eat = atoi(argv[3]);
	rules->time_sleep = atoi(argv[4]);
	if (argv[5])
		rules->nb_eat = atoi(argv[5]);
	else
		rules->nb_eat = __INT_MAX__;
	rules->all_ate = 0;
	if (rules->nb_philo < 1 || rules->time_die <= 0 || rules->time_eat <= 0
		|| rules->time_sleep <= 0 || rules->nb_eat <= 0)
		return (err_msg(1, "Wrong argument values !"));
	rules->philo = malloc(rules->nb_philo * sizeof(t_philosopher));
	if (!rules->philo)
		return (err_msg(1, "Allocation fail !"));
	rules->fork = malloc(rules->nb_philo * sizeof(pthread_mutex_t));
	if (!rules->fork)
	{
		free(rules->philo);
		rules->philo = NULL;
		return (err_msg(1, "Allocation fail !"));
	}
	return (0);
}

static int	init_philo(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
	{
		rules->philo[i].id = i;
		rules->philo[i].nb_eat = 0;
		rules->philo[i].fork_1 = i;
		rules->philo[i].fork_2 = (i + 1) % rules->nb_philo;
		rules->philo[i].rules = rules;
	}
	return (0);
}

static int	init_mutex(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
	{
		if (pthread_mutex_init(&rules->fork[i], NULL))
			return (err_msg(1, "Mutex initialisation fail !"));
	}
	if (pthread_mutex_init(&rules->writing, NULL))
		return (err_msg(1, "Mutex initialisation fail !"));
	return (0);
}

int	init_all(char **argv, t_rules *rules)
{
	int	err;

	if (init_rules(argv, rules))
		return (1);
	if (init_philo(rules))
		return (1);
	if (init_mutex(rules))
		return (1);
	return (0);
}
