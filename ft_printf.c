/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:03:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/04 17:47:43 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
t_flags	init(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.star = 0;
	flags.min_width = 0;
	flags.point = 0;
	flags.precision = 0;
	flags.type = 0;
	return (flags);
}

int		check_format(char *input, va_list args)
{
	int		count;
	int		i;
	t_flags	flags;
	
	if (!input)
		return (0);
	i = 0;
	flags = init();
	count = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
		{
			i += set_params(&input[i], &flags) + 1;
			printf("\nflag_zero: %d\nflag_minus: %d\nflag_star: %d\nflag_mw: %d\nflag_point: %d\nflag_precision: %d\nflags.type: %c\n", flags.zero, flags.minus, flags.star, flags.min_width, flags.point, flags.precision, flags.type);
			printf("i: %s\n", &input[i]);
			//count += deal_cases(flags, args);
			//i vai ter de ser incrementado para saltar o fmtstr;
		}
		else
			count += ft_putchar(input[i]);
		i++;
	}
	return (count);
}


int		ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;
	char	*input;

	if (!(input = ft_strdup(fmt)))
		return (0);
	va_start(args, fmt);
	count = check_format(input, args);
	va_end(args);
	free(input);
	return (count);
}
