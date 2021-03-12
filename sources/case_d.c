/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:48:44 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/12 20:24:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*insert_zeros(char *nbr, int len, int f)
{
	char	*temp;
	int		flag;

	flag = 0;
	if (nbr[0] == '-')
	{
		if (f)
			len++;
		temp = nbr;
		nbr = ft_substr(nbr, 1, ft_strlen(nbr) - 1);
		free(temp);
		flag = 1;
	}
	while (len-- > 0)
	{
		temp = nbr;
		nbr = ft_strjoin("0", nbr);
		free(temp);
	}
	if (flag)
	{
		temp = nbr;
		nbr = ft_strjoin("-", nbr);
		free(temp);
	}
	return (nbr);
}

static char	*handle_precision(t_flags *flags, char *nbr)
{
	if (!ft_strncmp(nbr, "0", 1) && flags->point && flags->precision <= 0)
	{
		free(nbr);
		flags->zero = 0;
		return (ft_strdup(""));
	}
	if (flags->zero && !flags->point)
		nbr = insert_zeros(nbr, flags->min_width - (int)ft_strlen(nbr), 0);
	else if (flags->precision > (int)ft_strlen(nbr))
		nbr = insert_zeros(nbr, flags->precision - (int)ft_strlen(nbr), 1);
	else if (nbr[0] == '-' && flags->precision > (int)ft_strlen(nbr) - 1)
		nbr = insert_zeros(nbr, flags->precision - (int)ft_strlen(nbr), 1);
	flags->zero = 0;
	return (nbr);
}

int			case_d(t_flags *flags, va_list args)
{
	int		count;
	char	*nbr;

	count = 0;
	nbr = arg_conversions(flags, args);
	nbr = handle_precision(flags, nbr);
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
