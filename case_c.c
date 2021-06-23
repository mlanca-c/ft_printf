/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:40:49 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/30 10:51:08 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_c(t_flags *flags, va_list args)
{
	int		count;

	count = 0;
	if (flags->minus && flags->min_width)
	{
		count += ft_putchar(va_arg(args, int));
		count += handle_width(flags, 1);
	}
	else if (flags->min_width)
	{
		count += handle_width(flags, 1);
		count += ft_putchar(va_arg(args, int));
	}
	else
		count += ft_putchar(va_arg(args, int));
	return (count);
}
