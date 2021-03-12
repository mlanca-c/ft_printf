/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:53:17 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/12 13:24:34 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		case_p(t_flags *flags, va_list args)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = arg_conversions(flags, args);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr("0x");
		count += ft_putstr(ptr);
		count += handle_width(flags, count);
	}
	else if (flags->min_width)
	{
		count += handle_width(flags, 0); //TRATAR, 0 ESTA ERRADO VER
		count += ft_putstr("0x");
		count += ft_putstr(ptr);
	}
	else
	{
		count += ft_putstr("0x");
		count += ft_putstr(ptr);
	}
	free(ptr);
	return (count);
}
