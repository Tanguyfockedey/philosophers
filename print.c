/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:52:02 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/19 19:36:57 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_action(t_philosopher *philo, char *str)
{
	t_rules	*rules;

	rules = philo->rules;
	pthread_mutex_lock(&rules->writing);
	printf("%d\t%d %s\n", timestamp() - rules->start, philo->id + 1, str);
	pthread_mutex_unlock(&rules->writing);
}
