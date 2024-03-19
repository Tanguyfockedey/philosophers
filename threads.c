/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:03:41 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/19 21:25:20 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philosopher *philo)
{
	if (philo->id % 2)
		usleep(50);
	pthread_mutex_lock(&philo->rules->fork[philo->fork_1]);
	print_action(philo, "has taken a fork");
	pthread_mutex_lock(&philo->rules->fork[philo->fork_2]);
	print_action(philo, "has taken a fork");
	philo->time_last_eat = timestamp();
	print_action(philo, "is eating");
	philo->nb_eat++;
	precise_msleep(philo->rules->time_eat);
	pthread_mutex_unlock(&philo->rules->fork[philo->fork_1]);
	pthread_mutex_unlock(&philo->rules->fork[philo->fork_2]);
	print_action(philo, "is sleeping");
	precise_msleep(philo->rules->time_sleep);
	print_action(philo, "is thinking");

}

void	*live(void *void_philo)
{
	t_philosopher	*philo;

	philo = void_philo;
	philo->time_last_eat = timestamp();
	while (philo->nb_eat < philo->rules->nb_eat)
		philo_eat(philo);
	// philo_sleep(philo);
	// philo_think(philo);
	return (NULL);
}
void	*scythe(void *void_rules)
{
	(void)void_rules;
	return (NULL);
}

int		threads(t_rules *rules)
{
	int			i;
	pthread_t	ankou;

	rules->start = timestamp();
	i = -1;
	while (++i < rules->nb_philo)
	{
		if (pthread_create(&rules->philo[i].thread, NULL, &live, &rules->philo[i]))
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
