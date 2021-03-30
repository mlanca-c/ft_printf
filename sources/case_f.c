/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:37:55 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/30 10:52:35 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	handle_precision(t_flags *flags, double d)
{
	if (!flags->point)
		flags->precision = 6;
	else if (!flags->precision && !d)
		flags->precision = -1;
}

static char	*handle_zero(t_flags *flags, char *d, int *count)
{
	if (!(ft_strncmp("inf", d, 3)) || (!(ft_strncmp("-inf", d, 4))
			|| (!(ft_strncmp("nan", d, 3)))))
		flags->zero = 0;
	else if (d[0] == '-' && flags->zero)
	{
		*count += ft_putchar('-');
		d = ft_free_function("ft_substr", d, 1, (int)ft_strlen(d));
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
	return (d);
}

int	case_f(t_flags *flags, va_list args)
{
	int		count;
	char	*d;
	double	n;

	count = 0;
	n = va_arg(args, double);
	handle_precision(flags, n);
	d = ft_ftoa(n, flags->precision);
	d = handle_zero(flags, d, &count);
	d = handle_double(flags, d);
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
