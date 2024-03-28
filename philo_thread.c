/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:48:09 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/28 19:27:48 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	fork_lock(t_philosopher *philo)
{
	if (philo->id % 2)
	{
		if (pthread_mutex_lock(&philo->rules->fork[philo->fork_1]))
			return (1);
		print_action(philo, "has taken a fork");
		if (pthread_mutex_lock(&philo->rules->fork[philo->fork_2]))
			return (1);
		print_action(philo, "has taken a fork");
	}
	else
	{
		if (pthread_mutex_lock(&philo->rules->fork[philo->fork_2]))
			return (1);
		print_action(philo, "has taken a fork");
		if (pthread_mutex_lock(&philo->rules->fork[philo->fork_1]))
			return (1);
		print_action(philo, "has taken a fork");
	}
	return (0);
}

int	fork_unlock(t_philosopher *philo)
{
	if (philo->id % 2)
	{
		if (pthread_mutex_unlock(&philo->rules->fork[philo->fork_2]))
			return (1);
		if (pthread_mutex_unlock(&philo->rules->fork[philo->fork_1]))
			return (1);
	}
	else
	{
		if (pthread_mutex_unlock(&philo->rules->fork[philo->fork_1]))
			return (1);
		if (pthread_mutex_unlock(&philo->rules->fork[philo->fork_2]))
			return (1);
	}
	return (0);
}

int	philo_live(t_philosopher *philo)
{
	if (philo->rules->nb_philo < 2)
		return (0);
	if (fork_lock(philo))
		return (err_msg(1, "Fork lock fail !"));
	philo->time_last_eat = timestamp();
	print_action(philo, "is eating");
	philo->nb_eat++;
	sleeptill(philo, philo->time_last_eat + philo->rules->time_eat);
	if (fork_unlock(philo))
		return (err_msg(1, "Fork unlock fail !"));
	print_action(philo, "is sleeping");
	sleeptill(philo, philo->time_last_eat
		+ philo->rules->time_eat + philo->rules->time_sleep);
	print_action(philo, "is thinking");
	if (philo->rules->nb_philo % 2)
		sleeptill(philo, timestamp() + 1);
	return (0);
}

void	*philo_routine(void *void_philo)
{
	t_philosopher	*philo;

	philo = void_philo;
	philo->time_last_eat = timestamp();
	if (philo->id % 2)
		sleeptill(philo, philo->time_last_eat + philo->rules->time_eat / 2);
	while (!philo->rules->all_ate && !philo->rules->died)
		philo_live(philo);
	return (NULL);
}
