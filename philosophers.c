/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:13:29 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/19 16:00:51 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argcheck(argc, argv))
		return (1);
	if (init_all(argv, &rules))
	{
		free_struct(&rules);
		return (1);
	}
	if (threads(&rules))
	{
		free_struct(&rules);
		return (1);
	}
	printf("ok\n");
	printf("timestamp : %d\n", timestamp());
	free_struct(&rules);
}
