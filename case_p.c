/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:53:17 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/30 10:53:29 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*append_ptr(char *ptr)
{
	char	*temp;

	temp = ptr;
	ptr = ft_strjoin("0x", ptr);
	free(temp);
	return (ptr);
}

int	case_p(t_flags *flags, va_list args)
{
	int		count;
	char	*ptr;

	count = 0;
	ptr = arg_conversions(flags, args);
	if (flags->point)
		flags->zero = 0;
	ptr = handle_number(flags, ptr);
	ptr = append_ptr(ptr);
	if (flags->minus && flags->min_width)
	{
		count += ft_putstr(ptr);
		count += handle_width(flags, (int)ft_strlen(ptr));
	}
	else if (flags->min_width)
	{
		count += handle_width(flags, (int)ft_strlen(ptr));
		count += ft_putstr(ptr);
	}
	else
		count += ft_putstr(ptr);
	free(ptr);
	return (count);
}
