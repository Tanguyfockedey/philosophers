/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:41:00 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/25 15:30:46 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	msleep(int ms)
{
	int	t;

	t = timestamp() + ms;
	while (timestamp() < t)
		usleep(10);
}

void	sleeptill(int t)
{
	while (timestamp() < t)
		usleep(10);
}
