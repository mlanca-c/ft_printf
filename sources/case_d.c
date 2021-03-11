/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:12:24 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/11 18:42:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	absolute(int n)
{
	return (n > 0 ? n : -n);
}

static char	*handle_precision(t_flags *flags, int n)
{
	char	*temp;
	char	*nbr;
;
	if (flags->precision < 0 && flags->point)
	{
		flags->min_width = flags->precision;
		flags->precision = -1;
	}
	if (flags->min_width < 0)
	{
		flags->minus = 1;
		flags->min_width *= -1;
	}
	nbr = ft_itoa(absolute(n));
	while (flags->precision > 0 && flags->precision > (int)ft_strlen(nbr))
	{
		temp = nbr;
		nbr = ft_strjoin("0", nbr);
		free(temp);
	}
	if (n < 0)
	{
		temp = nbr;
		nbr = ft_strjoin("-", nbr);
		free(temp);
	}
	return (nbr);
}

int		case_d(t_flags *flags, va_list args)
{
	int		count;
	int		n;
	char	*nbr;

	count = 0;
	n = va_arg(args, int);
	nbr = handle_precision(flags, n);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(nbr);
		while (flags->min_width-- > (int)ft_strlen(nbr))
			count += ft_putchar(' ');
	}
	else if (flags->min_width)
	{
		while (flags->zero && flags->min_width-- > (int)ft_strlen(nbr))
			count += ft_putchar('0');
		while (!flags->zero && flags->min_width-- > (int)ft_strlen(nbr))
			count += ft_putchar(' ');
		count += ft_putstr(nbr);
	}
	else
		count += ft_putstr(nbr);
	free(nbr);
	return (count);
}
