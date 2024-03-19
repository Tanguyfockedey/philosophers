/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:22:08 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/19 15:22:08 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	overflow(char *str)
{
	int	i;
	int	overflow;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] == '0')
		i++;
	overflow = strlen(&str[i]);
	if (overflow < 10)
		return (0);
	if (overflow > 10)
		return (1);
	if (str[i] > '2' || str[i + 1] > '1' || str[i + 2] > '4'
		|| str[i + 3] > '7' || str[i + 4] > '4' || str[i + 5] > '8'
		|| str[i + 6] > '3' || str[i + 7] > '6' || str[i + 8] > '4'
		|| (str[0] != '-' && str[i + 9] > '7')
		|| (str[0] == '-' && str[i + 9] > '8'))
		return (1);
	return (0);
}

static int	str_isint(char *str)
{
	int	i;

	i = -1;
	if (!isdigit(str[0]) && str[0] != '+' && str[0] != '-')
		return (0);
	if (str[0] == '+' || str[0] == '-')
	{
		i++;
		if (!str[1])
			return (0);
	}
	while (str[++i])
		if (!isdigit(str[i]))
			return (0);
	if (overflow(str))
		return (0);
	return (1);
}

int	argcheck(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (str_isint(argv[1]) && str_isint(argv[2])
			&& str_isint(argv[3]) && str_isint(argv[4]))
		{
			if (argc == 5)
				return (0);
			else
				if (str_isint(argv[5]))
					return (0);
		}
	}
	return (err_msg(1, "Wrong number of argument !"));
}
