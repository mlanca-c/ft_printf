/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:38:55 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/05 18:51:42 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	handle_star(t_flags *flags, int arg)
{
	if (!flags->point)
		flags->min_width = arg;
	else
		flags->precision = arg;
	flags->star += 1;
}

int		handle_width(t_flags *flags, char *input)
{
	int		i;

	i = 0;
	if (!flags->point)
		flags->min_width = ft_atoi(input);
	else
		flags->precision = ft_atoi(input);
	while (ft_isdigit(input[i]))
		i++;
	return (--i);
}

int		set_params(char *input, t_flags *flags, va_list args)
{
	int		i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '-')
			flags->minus = 1;
		else if (input[i] == '0' && !flags->minus)
			flags->zero = 1;
		else if (input[i] == '.')
			flags->point = 1;
		else if (input[i] == '*')
			handle_star(flags, va_arg(args, int));
		else if (ft_isdigit(input[i]))
			i += handle_width(flags, &input[i]);
		else if (ft_strchr("cspdiuxX%", input[i]) && i != 0)
		{
			flags->type = input[i];
			break ;
		}
		else if (ft_isalpha(input[i]))
			break ;
	}
	return (flags->type == 0 ? 0 : i);
}
