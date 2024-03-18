/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:13:27 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/18 20:04:44 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	int	nb_meals;
	int	time_last_meal;
	
}	t_philosopher;

typedef struct	s_rules
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	t_philosopher	*philo;
	pthread_mutex_t	*fork;
}	t_rules;

int		ft_argcheck(int argc, char **argv);
int		ft_atoi(const char *string);
void	ft_free(t_rules *rules);
int		ft_init(char **argv, t_rules *rules);
int		ft_threads(t_rules *rules);
#endif
