/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:07:22 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/19 15:25:47 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_struct(t_rules *rules)
{
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
