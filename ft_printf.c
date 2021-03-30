/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:03:39 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/30 11:01:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

t_flags	init(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.star = 0;
	flags.min_width = 0;
	flags.point = 0;
	flags.precision = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	flags.l = 0;
	flags.h = 0;
	flags.type = 0;
	return (flags);
}

int	check_format(char *input, va_list args)
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
			count += get_case(&flags, args, &count);
		}
		else
			count += ft_putchar(input[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		count;
	char	*input;

	input = ft_strdup(fmt);
	if (!input)
		return (0);
	va_start(args, fmt);
	count = check_format(input, args);
	va_end(args);
	free(input);
	return (count);
}
