/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:01:40 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/11 12:27:08 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		case_c(t_flags *flags, va_list args)
{
	int		count;

	count = 0;
	if (flags->min_width < 0)
	{
		flags->min_width *= -1;
		flags->minus = 1;
	}
	if (flags->minus && flags->min_width)
	{
		count += ft_putchar(va_arg(args, int));
		while (--flags->min_width)
			count += ft_putchar(' ');
	}
	else if (flags->min_width)
	{
		while (flags->zero && --flags->min_width)
			count += ft_putchar('0');
		while (!flags->zero && --flags->min_width)
			count += ft_putchar(' ');
		count += ft_putchar(va_arg(args, int));
	}
	else
		count += ft_putchar(va_arg(args, int));
	return (count);
}
