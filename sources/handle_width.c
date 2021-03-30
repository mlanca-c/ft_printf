/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 11:01:46 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/30 10:54:29 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_width(t_flags *flags, int len)
{
	int		count;

	count = 0;
	while (flags->zero && flags->min_width-- > len)
		count += ft_putchar('0');
	while (!flags->zero && flags->min_width-- > len)
		count += ft_putchar(' ');
	return (count);
}
