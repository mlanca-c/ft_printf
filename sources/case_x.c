/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:58:25 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/13 20:47:36 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		case_x(t_flags *flags, va_list args)
{
	int		count;
	char	*hex;

	count = 0;
	hex = arg_conversions(flags, args);
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
