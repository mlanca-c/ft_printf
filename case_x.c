/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:58:25 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/04/20 10:02:58 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_hash(t_flags *flags, char *hex, int *count)
{
	if (!(flags->hash && ft_strncmp("0", hex, 2)))
	{
		flags->hash = 0;
		return (hex);
	}
	if (flags->type == 'x')
		hex = ft_free_function("ft_strjoin", "0x", hex, 2);
	else
		hex = ft_free_function("ft_strjoin", "0X", hex, 2);
	if (flags->point)
		flags->zero = 0;
	else if (flags->zero)
	{
		if (flags->type == 'x')
			*count += ft_putstr("0x");
		else
			*count += ft_putstr("0X");
		flags->min_width -= 2;
	}
	return (hex);
}

int	case_x(t_flags *flags, va_list args)
{
	int		count;
	char	*hex;

	count = 0;
	hex = arg_conversions(flags, args);
	hex = handle_hash(flags, hex, &count);
	if (flags->point)
		flags->zero = 0;
	hex = handle_number(flags, hex);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(hex);
		count += handle_width(flags, (int)ft_strlen(hex));
	}
	else if (flags->min_width)
	{
		count += handle_width(flags, (int)ft_strlen(hex));
		count += ft_putstr(hex);
	}
	else
		count += ft_putstr(hex);
	free(hex);
	return (count);
}
