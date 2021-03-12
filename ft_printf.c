/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:03:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/12 20:22:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_flags(t_flags *flags)
{
	printf("\nminus: %d\n", flags->minus);
	printf("zero: %d\n", flags->zero);
	printf("star: %d\n", flags->star);
	printf("width: %d\n", flags->min_width);
	printf("point: %d\n", flags->point);
	printf("precision: %d\n", flags->precision);
	printf("type: %c\n", flags->type);
}

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
	count = 0;
	while (input[i])
	{
		flags = init();
		if (input[i] == '%' && input[i + 1])
		{
			i += set_params(&input[i], &flags, args);
			count += get_case(&flags, args);
		//	print_flags(&flags);
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
