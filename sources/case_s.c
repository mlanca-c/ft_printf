/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 19:46:18 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/11 12:46:46 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	handle_flags(t_flags *flags, char *str)
{
	if (flags->min_width < 0)
	{
		flags->minus = 1;
		flags->min_width *= -1;
	}
	if (flags->precision > flags->min_width)
		flags->min_width = 0;
	if (flags->point && flags->precision == -1)
		flags->precision = 0;
	else if (flags->precision > (int)ft_strlen(str) || flags->precision <= -1)
		flags->precision = (int)ft_strlen(str);
}

static int	handle_null(t_flags *flags)
{
	int		count;
	char	*str;

	str = ft_strdup("(null)");
	handle_flags(flags, str);
	count = 0;
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr_len(str, flags->precision);
		while (flags->min_width-- > flags->precision)
			count += ft_putchar(' ');
	}
	else if (flags->min_width)
	{
		while (flags->zero && flags->min_width-- > flags->precision)
			count += ft_putchar('0');
		while (!flags->zero && flags->min_width-- > flags->precision)
			count += ft_putchar(' ');
		count += ft_putstr_len(str, flags->precision);
	}
	else
		count += ft_putstr_len(str, flags->precision);
	free(str);
	return (count);
}

int		case_s(t_flags *flags, va_list args)
{
	int		count;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		return (handle_null(flags));
	handle_flags(flags, str);
	count = 0;
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr_len(str, flags->precision);
		while (flags->min_width-- > flags->precision)
			count += ft_putchar(' ');
	}
	else if (flags->min_width)
	{
		while (flags->zero && flags->min_width-- > flags->precision)
			count += ft_putchar('0');
		while (!flags->zero && flags->min_width-- > flags->precision)
			count += ft_putchar(' ');
		count += ft_putstr_len(str, flags->precision);
	}
	else
		count += ft_putstr_len(str, flags->precision);
	return (count);
}
