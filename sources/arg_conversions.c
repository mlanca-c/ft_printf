/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:13:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/13 19:10:49 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*arg_conversions(t_flags *flags, va_list args)
{
	if (flags->type == 'c')
		return (va_arg(args, int));
	if (flags->type == 's')
		return (va_arg(args, char *));
	if (flags->type == 'd' || flags->type == 'i')
		return (ft_itoa(va_arg(args, int)));
	if (flags->type == 'u')
		return (ft_itoa_base(va_arg(args, unsigned int), "0123456789"));
	if (flags->type == 'x')
		return (ft_itoa_base(va_arg(args, unsigned int), "0123456789abcdef"));
	if (flags->type == 'X')
		return (ft_itoa_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (flags->type == 'p')
		return (ft_itoa_base(va_arg(args, unsigned long), "0123456789abcdef"));
	return (NULL);
}
