/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:18:57 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/05 18:58:12 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_case(t_flags *flags, va_list args)
{
	if (flags->type == 'c')
		return (case_c(flags, args));
	else if (flags->type == 's')
		return (case_s(flags, args));
	else if (flags->type == 'p')
		return (case_p(flags, args));
	else if (flags->type == 'd')
		return (case_d(flags, args));
	else if (flags->type == 'i')
		return (case_i(flags, args));
	else if (flags->type == 'u')
		return (case_u(flags, args));
	else if (flags->type == 'x')
		return (case_x(flags, args));
	else if (flags->type == 'X')
		return (case_upperx(flags, args));
	else if (flags->type == '%')
		return (case_percentage(flags));
	return (0);
}
