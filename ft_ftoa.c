/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:47:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/06/23 12:47:33 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_remainder(long double numer, long double denom)
{
	if (numer < 0)
		numer *= -1;
	return (numer - (denom * (long long)(numer / denom)));
}

static char	*get_dec(long double d, int precision, char *decimal)
{
	int		len;
	int		p;

	p = precision;
	while (p-- > 0)
		decimal = ft_free_function("ft_strjoin", decimal, "0", 1);
	len = (int)ft_strlen(decimal) - 1;
	while (precision-- > 0)
	{
		if (d == -9223372036854775807 || d >= 9223372036854775807
			|| !ft_remainder(d, 1))
			decimal[len - precision] = '0';
		else
		{
			d *= 10;
			decimal[len - precision] = (long long int)d % 10 + '0';
		}
	}
	return (decimal);
}

static char	*get_int(long double d, int precision)
{
	char		*integral;
	long long	n;

	n = (long long)d;
	integral = ft_itoa(n);
	if (d < 0 && d > -1)
		integral = ft_free_function("ft_strjoin", "-", integral, 2);
	if (d < 0)
		d *= -1;
	integral = ft_free_function("ft_strjoin", integral, ".", 1);
	return (get_dec(d, precision, integral));
}

char	*ft_ftoa(long double d, int precision)
{
	char		*number;

	if (d == (1.0 / 0.0))
		return (ft_strdup("inf"));
	else if (d == -(1.0 / 0.0))
		return (ft_strdup("-inf"));
	else if (!(d == d))
		return (ft_strdup("nan"));
	else if (precision < 0)
		return (ft_strdup("0"));
	if (d == (9223372036854775807 * 1.0))
	{
		if (precision == 0)
			return (ft_strdup("9223372036854775808"));
		number = ft_strdup("9223372036854775808.");
		while (precision-- > 0)
			number = ft_free_function("ft_strjoin", number, "0", 1);
	}
	else
	{
		number = get_int(d, precision + 1);
		number = ft_roundup_number(number);
	}
	return (number);
}
