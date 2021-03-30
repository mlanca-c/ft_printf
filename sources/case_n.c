/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:27:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/30 10:53:05 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	case_n(t_flags *flags, va_list args, int *count)
{
	if (flags->l == 1)
		*va_arg(args, long int *) = (long int)*count;
	else if (flags->l == 2)
		*va_arg(args, long long int *) = (long long int)*count;
	else if (flags->h == 1)
		*va_arg(args, short int *) = (short int)*count;
	else if (flags->h == 2)
		*va_arg(args, signed char *) = (signed char)*count;
	else
		*va_arg(args, int *) = *count;
	return (0);
}
