/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:38:55 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/15 16:12:44 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			set_params(char *input, t_flags *flags, va_list args)
{
	int		i;

	i = 0;
	while (input[i++])
	{
		if (input[i] == '-' || input[i] == '0'
				|| input[i] == '.' || input[i] == '*')
			handle_flags(input[i], flags, args);
		else if (input[i] == '#' || input[i] == ' ' || input[i] == '+')
			handle_flags(input[i], flags, args);
		else if ((input[i] == 'l' && !flags->l)
				|| (input[i] == 'h' && !flags->h))
			i += handle_lh(&input[i], flags);
		else if (ft_isdigit(input[i]))
			i += handle_digit(flags, &input[i]);
		else if (ft_strchr("cspdiuxX%nfgeo", input[i]) && i != 0)
		{
			flags->type = input[i];
			break ;
		}
		else if (ft_isalpha(input[i]))
			break ;
	}
	handle_minus(flags);
	return (flags->type == 0 ? 0 : i);
}
