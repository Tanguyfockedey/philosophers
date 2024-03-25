/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 20:03:41 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/25 22:36:20 by tafocked         ###   ########.fr       */
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

int	philo_eat(t_philosopher *philo)
{
	if (fork_lock(philo))
		return (err_msg(1, "Fork lock fail !"));
	philo->time_last_eat = timestamp();
	print_action(philo, "is eating");
	philo->nb_eat++;
	sleeptill(philo->time_last_eat + philo->rules->time_eat);
	if (fork_unlock(philo))
		return (err_msg(1, "Fork unlock fail !"));
	print_action(philo, "is sleeping");
	sleeptill(philo->time_last_eat + philo->rules->time_eat + philo->rules->time_sleep);
	print_action(philo, "is thinking");
	msleep(philo->rules->time_eat / 2);
	return (0);
}

void	*live(void *void_philo)
{
	t_philosopher	*philo;

	philo = void_philo;
	philo->time_last_eat = timestamp();
	// if (philo->id % 2)
	// 	msleep(philo->rules->time_eat / 2);
	while (philo->nb_eat < philo->rules->nb_eat //philo dies when they stop eating when nb_eat is reached.
			&& !philo->rules->died)
		philo_eat(philo);
	return (NULL);
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
			print_action(&rules->philo[i], "died");
			rules->died = 1;
			return (NULL);
		}
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
	rules->all_ate = 1;
	if (pthread_join(ankou, NULL))
		return (err_msg(1, "Failed to join thread !"));
	return (0);
}
