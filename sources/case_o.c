/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:54:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/30 10:53:23 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*handle_hash(t_flags *flags, char *oct, int *count)
{
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
	if (flags->hash && ft_strncmp("0", oct, 2))
		oct = handle_hash(flags, oct, &count);
	else
		flags->hash = 0;
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
