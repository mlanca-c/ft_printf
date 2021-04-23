/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_percentage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:46:40 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/30 10:53:33 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_percentage(t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->minus && flags->min_width)
	{
		count += ft_putchar('%');
		count += handle_width(flags, 1);
	}
	else if (flags->min_width)
	{
		count += handle_width(flags, 1);
		count += ft_putchar('%');
	}
	else
		count += ft_putchar('%');
	return (count);
}
