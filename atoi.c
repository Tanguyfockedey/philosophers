/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:00:51 by tafocked          #+#    #+#             */
/*   Updated: 2024/03/19 15:26:42 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The atoi function converts the initial part of string to a signed integer, 
	which is returned as a value of type int.
*/

static char	*prestr(char *str, char *sign)
{
	int	i;

	*sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			*sign *= -1;
	}
	return (&str[i]);
}

int	atoi(const char *string)
{
	char	sign;
	char	*str;
	int		i;
	int	unb;
	int	mult10;

	i = 0;
	unb = 0;
	mult10 = 1;
	str = prestr((char *)string, &sign);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (i > 0)
	{
		i--;
		unb = unb + (str[i] - '0') * mult10;
		mult10 *= 10;
	}
	return (sign * unb);
}
