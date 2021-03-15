/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:24:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/15 17:32:31 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar(wchar_t chr)
{
	int		count;

	count = 0;
	if (chr <= 0x7F)
		count += ft_putchar(chr);
	else if (chr <= 0x7FF)
	{
		count += ft_putchar((chr >> 6) + 0xC0);
		count += ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0xFFFF)
	{
		count += ft_putchar((chr >> 12) + 0xE0);
		count += ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		count += ft_putchar((chr & 0x3F) + 0x80);
	}
	else if (chr <= 0x10FFFF)
	{
		count += ft_putchar((chr >> 18) + 0xF0);
		count += ft_putchar(((chr >> 12) & 0x3F) + 0x80);
		count += ft_putchar(((chr >> 6) & 0x3F) + 0x80);
		count += ft_putchar((chr & 0x3F) + 0x80);
	}
	return (count);
}
