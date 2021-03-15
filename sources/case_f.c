/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:37:55 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/15 20:02:08 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	handle_precision(t_flags *flags)
{
	if (!flags->point)
		flags->precision = 6;
}

static char		*handle_zero(t_flags *flags, char *nbr, int *count)
{
	if (nbr[0] == '-' && flags->zero)
	{
		*count += ft_putchar('-');
		nbr = ft_free_function("ft_substr", nbr, 1, (int)ft_strlen(nbr));
		flags->min_width -= 1;
	}
	else if (flags->space && flags->zero)
	{
		*count += ft_putchar(' ');
		flags->min_width -= 1;
	}
	else if (flags->plus && flags->zero)
	{
		*count += ft_putchar('+');
		flags->min_width -= 1;
	}
	return (nbr);
}

int			case_f(t_flags *flags, va_list args)
{
	int		count;
	char	*d;

	count = 0;
	handle_precision(flags);
	d = ft_ftoa(va_arg(args, double), flags->precision);
	d = handle_zero(flags, d, &count);
	d = handle_number(flags, d);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(d);
		count += handle_width(flags, (int)ft_strlen(d));
	}
	else if (flags->min_width)
	{
		count += handle_width(flags, (int)ft_strlen(d));
		count += ft_putstr(d);
	}
	else
		count += ft_putstr(d);
	free(d);
	return (count);
}
