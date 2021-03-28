/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:38:28 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/28 19:59:21 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_dec(long double d, int precision, char *integral)
{
	char		*decimal;
	char		*temp;
	long double	value;

	value = d - (long long int)d;
	value *= ft_power(10, precision + 2);
	decimal = ft_llitoa_base(value + 0.5, "0123456789");
	temp = decimal;
	decimal = ft_substr(decimal, 0, (int)ft_strlen(decimal) - 2);
	free(temp);
	while ((int)ft_strlen(decimal) < precision)
		decimal = ft_free_function("ft_strjoin", "0", decimal, 2);
	temp = decimal;
	decimal = ft_free_function("ft_strjoin", integral, decimal, 1);
	free(temp);
	return (decimal);
}

static char	*get_int(long double d, int precision)
{
	char		*integral;
	long long	n;

	n = (long long)d;
	integral = ft_llitoa(n);
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
