/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:19:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/13 18:26:27 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*handle_zero(t_flags *flags, char *nbr, int *count)
{
	if (flags->precision < 0)
	{
		flags->min_width = -flags->precision;
		flags->precision = 0;
		flags->minus = 1;
		flags->point = 0;
	}
	if (flags->point)
		flags->zero = 0;
	else if (nbr[0] == '-' && flags->zero)
	{
		*count += ft_putchar('-');
		nbr = ft_free_function("ft_substr", nbr, 1, (int)ft_strlen(nbr));
		flags->min_width -= 1;
	}
	return (nbr);
}

static char		*handle_positive(t_flags *flags, char *nbr)
{
	if (!ft_strncmp(nbr, "0", 1) && flags->point && !flags->precision)
		nbr = ft_free_function("ft_strdup", nbr, "");
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", nbr, "0");
	return (nbr);
}

static char		*handle_negative(t_flags *flags, char *nbr)
{
	nbr = ft_free_function("ft_substr", nbr, 1, (int)ft_strlen(nbr));
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", nbr, "0");
	nbr = ft_free_function("ft_strjoin", nbr, "-");
	return (nbr);
}

int				case_d(t_flags *flags, va_list args)
{
	int		count;
	char	*nbr;

	count = 0;
	nbr = arg_conversions(flags, args);
	nbr = handle_zero(flags, nbr, &count);
	if (nbr[0] == '-')
		nbr = handle_negative(flags, nbr);
	else
		nbr = handle_positive(flags, nbr);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(nbr);
		count += handle_width(flags, (int)ft_strlen(nbr));
	}
	else if (flags->min_width)
	{
		count += handle_width(flags, (int)ft_strlen(nbr));
		count += ft_putstr(nbr);
	}
	else
		count += ft_putstr(nbr);
	free(nbr);
	return (count);
}
