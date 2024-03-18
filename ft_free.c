/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:07:22 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/18 18:22:34 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_rules *rules)
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
