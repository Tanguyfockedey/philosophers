/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:03:41 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/28 19:33:16 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ate_check(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
	{
		if (rules->philo[i].nb_eat < rules->nb_eat)
			return ;
	}
	rules->all_ate = 1;
}

int	death_check(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
	{
		pthread_mutex_lock(&rules->eating);
		if ((rules->philo[i].time_last_eat) < timestamp() - rules->time_die)
		{
			rules->died = 1;
			printf("%d\t%d\tdied\n",
				timestamp() - rules->start, rules->philo[i].id + 1);
			pthread_mutex_unlock(&rules->eating);
			return (1);
		}
		pthread_mutex_unlock(&rules->eating);
	}
	return (0);
}

void	*observer_routine(void *void_rules)
{
	t_rules	*rules;

	rules = void_rules;
	while (!rules->all_ate)
	{
		if (death_check(rules))
			return (NULL);
		ate_check(rules);
		msleep(1);
	}
	return (NULL);
}

int	threads(t_rules *rules)
{
	int			i;
	pthread_t	observer;

	rules->start = timestamp();
	if (pthread_create(&observer, NULL, &observer_routine, rules))
		return (err_msg(1, "Failed to create thead !"));
	i = -1;
	while (++i < rules->nb_philo)
	{
		if (pthread_create(&rules->philo[i].thread, NULL,
				&philo_routine, &rules->philo[i]))
			return (err_msg(1, "Failed to create thread !"));
	}
	if (pthread_join(observer, NULL))
		return (err_msg(1, "Failed to join thread !"));
	i = -1;
	while (++i < rules->nb_philo)
	{
		if (pthread_join(rules->philo[i].thread, NULL))
			return (err_msg(1, "Failed to join thread !"));
	}
	return (0);
}
