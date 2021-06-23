/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:27:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/04/23 15:55:40 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_n(t_flags *flags, va_list args, int *count)
{
	if (flags->l == 1)
		*(long int *)va_arg(args, long int *) = *count;
	else if (flags->l == 2)
		*(long long int *)va_arg(args, long long int *) = *count;
	else if (flags->h == 1)
		*(short int *)va_arg(args, short int *) = *count;
	else if (flags->h == 2)
		*(signed char *)va_arg(args, signed char *) = *count;
	else
		*va_arg(args, int *) = *count;
	return (0);
}
