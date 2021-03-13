/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:56:22 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/13 20:34:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*handle_precision(t_flags *flags, char *nbr)
{
	if (!ft_strncmp(nbr, "0", 1) && flags->point && !flags->precision)
		nbr = ft_free_function("ft_strdup", nbr, "");
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", nbr, "0");
	return (nbr);
}

int				case_u(t_flags *flags, va_list args)
{
	int		count;
	char	*nbr;

	count = 0;
	nbr = arg_conversions(flags, args);
	if (flags->point)
		flags->zero = 0;
	nbr = handle_precision(flags, nbr);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(nbr);
		count += handle_width(flags, ft_strlen(nbr));
	}
	else if (flags->min_width)
	{
		count += handle_width(flags, ft_strlen(nbr));
		count += ft_putstr(nbr);
	}
	else
		count += ft_putstr(nbr);
	free(nbr);
	return (count);
}
