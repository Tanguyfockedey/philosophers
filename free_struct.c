/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:07:22 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/28 19:25:08 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_struct(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
		pthread_mutex_destroy(&rules->fork[i]);
	pthread_mutex_destroy(&rules->writing);
	if (rules->philo)
	{
		free(rules->philo);
		rules->philo = NULL;
	}
	if (rules->fork)
	{
		free(rules->fork);
		rules->fork = NULL;
	}
}
