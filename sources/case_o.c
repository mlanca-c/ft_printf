/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:54:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/15 16:54:26 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		case_o(t_flags *flags, va_list args)
{
	int		count;
	char	*oct;

	count = 0;
	oct = arg_conversions(flags, args);
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
