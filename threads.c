/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:03:41 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/19 15:58:44 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*live(void *void_philo)
{
	t_philosopher	*philo;

	philo = void_philo;
	philo->time_last_meal = timestamp();
	// philo_eat();
	// philo_sleep();
	// philo_think();
	return (NULL);
}

int		threads(t_rules *rules)
{
	int	 i;

	i = -1;
	while (++i < rules->nb_philo)
	{
		if (pthread_create(&rules->philo[i].thread, NULL, &live, &rules->philo[i]))
			return (err_msg(1, "Failed to create thread !"));
	}
	i = -1;
	while (++i < rules->nb_philo)
	{
		if (pthread_join(rules->philo[i].thread, NULL))
			return (err_msg(1, "Failed to join thread !"));
	}
	return (0);
}
