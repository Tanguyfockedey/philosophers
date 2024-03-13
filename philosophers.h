/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:13:27 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/13 18:13:18 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_rules
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	pthread_mutex_t	*fork;
	t_philosopher	*philo;
}	t_rules;

typedef struct s_philosopher
{
	int	id;
	int	nb_meals;
	int	time_last_meal;
	
}	t_philosopher;

int		ft_argcheck(int argc, char **argv);
int		ft_atoi(const char *string);
int		ft_init(char **argv, t_rules *rules);
#endif
