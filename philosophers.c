/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:13:29 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/13 17:35:28 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	int		err;
	t_rules	rules;

	if ((err = ft_argcheck(argc, argv)))
		return (err);
	if ((err = ft_init(argv, &rules)))
		return (err);
	printf("ok\n");
}
