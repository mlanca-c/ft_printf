/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:54:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/04/20 10:05:10 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_hash(t_flags *flags, char *oct, int *count)
{
	if (!(flags->hash && ft_strncmp("0", oct, 2)))
	{
		flags->hash = 0;
		return (oct);
	}
	oct = ft_free_function("ft_strjoin", "0", oct, 2);
	if (flags->point)
		flags->zero = 0;
	else if (flags->zero)
	{
		*count += ft_putchar('0');
		flags->min_width -= 1;
	}
	return (oct);
}

int	case_o(t_flags *flags, va_list args)
{
	int		count;
	char	*oct;

	count = 0;
	oct = arg_conversions(flags, args);
	oct = handle_hash(flags, oct, &count);
	if (flags->point)
		flags->zero = 0;
	oct = handle_number(flags, oct);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(oct);
		count += handle_width(flags, (int)ft_strlen(oct));
	}
	else if (flags->min_width)
	{
		count += handle_width(flags, (int)ft_strlen(oct));
		count += ft_putstr(oct);
	}
	else
		count += ft_putstr(oct);
	free(oct);
	return (count);
}
