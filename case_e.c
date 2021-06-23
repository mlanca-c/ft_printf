/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:38:45 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/30 10:51:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	case_e(t_flags *flags, va_list args)
{
	int		count;

	if (flags->type == 'c')
	{
		va_arg(args, int);
	}
	count = 0;
	return (count);
}
