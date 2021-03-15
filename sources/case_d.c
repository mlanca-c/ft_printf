/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:19:20 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/15 18:18:42 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*handle_zero(t_flags *flags, char *nbr, int *count)
{
	if (flags->point)
		flags->zero = 0;
	else if (nbr[0] == '-' && flags->zero)
	{
		*count += ft_putchar('-');
		nbr = ft_free_function("ft_substr", nbr, 1, (int)ft_strlen(nbr));
		flags->min_width -= 1;
	}
	else if (flags->space && flags->zero)
	{
		*count += ft_putchar(' ');
		flags->min_width -= 1;
	}
	else if (flags->plus && flags->zero)
	{
		*count += ft_putchar('+');
		flags->min_width -= 1;
	}
	return (nbr);
}

int				case_d(t_flags *flags, va_list args)
{
	int		count;
	char	*nbr;

	count = 0;
	nbr = arg_conversions(flags, args);
	nbr = handle_zero(flags, nbr, &count);
	nbr = handle_number(flags, nbr);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(nbr);
		count += handle_width(flags, (int)ft_strlen(nbr));
	}
	else if (flags->min_width)
	{
		count += handle_width(flags, (int)ft_strlen(nbr));
		count += ft_putstr(nbr);
	}
	else
		count += ft_putstr(nbr);
	free(nbr);
	return (count);
}
