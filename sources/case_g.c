/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:38:29 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/15 16:06:39 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		case_g(t_flags *flags, va_list args)
{
	int		count;

	if (flags->type == 'c')
	{
		va_arg(args, int);
	}
	count = 0;
	return (count);
}
