/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:13:27 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/19 16:12:07 by tafocked         ###   ########.fr       */
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
	int				id;
	int				nb_meals;
	int				time_last_meal;
	int				fork_1;
	int				fork_2;
	pthread_t		thread;
	struct s_rules	*rules;
}	t_philosopher;

typedef struct	s_rules
{
	int				start;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_eat;
	t_philosopher	*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	writing;
	//pthread_mutex_t	*fork;
}	t_rules;

int		argcheck(int argc, char **argv);
int		atoi(const char *string);
int		err_msg(int err_val, char *err_msg);
void	free_struct(t_rules *rules);
int		init_all(char **argv, t_rules *rules);
int		threads(t_rules *rules);
int		timestamp(void);

#endif
