/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:03:41 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/26 15:14:49 by tafocked         ###   ########.fr       */
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

void	*scythe(void *void_rules)
{
	t_rules	*rules;
	int		i;

	i = 0;
	rules = void_rules;
	msleep(rules->time_die / 2);
	while (!rules->all_ate)
	{
		if ((rules->philo[i].time_last_eat) < timestamp() - rules->time_die)
		{
			rules->died = 1;
			printf("%d\t%d died\n",
				timestamp() - rules->start, rules->philo[i].id + 1);
			return (NULL);
		}
		ate_check(rules);
		i++;
		if (i == rules->nb_philo)
			i = 0;
	}
	return (NULL);
}

int	threads(t_rules *rules)
{
	int			i;
	pthread_t	ankou;

	rules->start = timestamp();
	i = -1;
	while (++i < rules->nb_philo)
	{
		if (pthread_create(&rules->philo[i].thread, NULL,
				&live, &rules->philo[i]))
			return (err_msg(1, "Failed to create thread !"));
	}
	if (pthread_create(&ankou, NULL, &scythe, rules))
		return (err_msg(1, "Failed to create thead !"));
	i = -1;
	while (++i < rules->nb_philo)
	{
		if (pthread_join(rules->philo[i].thread, NULL))
			return (err_msg(1, "Failed to join thread !"));
	}
	if (pthread_join(ankou, NULL))
		return (err_msg(1, "Failed to join thread !"));
	return (0);
}
