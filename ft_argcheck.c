/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 14:00:24 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/06 14:00:24 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_argcheck(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (ft_str_isint(argv[1]) && ft_str_isint(argv[2])
			&& ft_str_isint(argv[3]) && ft_str_isint(argv[4]))
		{
			if (argc == 5)
				return ;
			else
				if (ft_str_isint(argv[5]))
					return ;
		}
	}
	printf("Wrong arguments !\n");
	exit();
	}
