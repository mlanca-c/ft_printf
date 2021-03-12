/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:52:01 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/12 17:22:55 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*handle_precision(t_flags *flags, char *s)
{
	if (!flags->precision && flags->point)
		s = ft_strdup("");
	else if (flags->precision < 0)
	{
		flags->precision = 0;
		s = ft_strdup(s);
	}
	else if (flags->precision < (int)ft_strlen(s) && flags->point)
		s = ft_substr(s, 0, flags->precision);
	else
		s = ft_strdup(s);
	return (s);
}

int			case_s(t_flags *flags, va_list args)
{
	int		count;
	char	*s;

	count = 0;
	s = va_arg(args, char *);
	if (!s)
		s = "(null)";
	s = handle_precision(flags, s);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(s);
		count += handle_width(flags, (int)ft_strlen(s));
	}
	else if (flags->min_width)
	{
		count += handle_width(flags, (int)ft_strlen(s));
		count += ft_putstr(s);
	}
	else
		count += ft_putstr(s);
	free(s);
	return (count);
}
