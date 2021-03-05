/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parameters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:36:34 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/04 20:27:16 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		set_params(char *input, t_flags *flags)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '-')
			flags->minus = 1;
		else if (input[i] == '0' && flags->minus != 1)
			flags->zero = 1;
		else if (input[i] == '*')
			flags->star += 1;
		else if (ft_isdigit(input[i]) && flags->point == 0)
			flags->min_width = ft_atoi(&input[i]);
		else if (input[i] == '.')
			flags->point = 1;
		else if (ft_isdigit(input[i]) && flags->point != 0)
			flags->precision = ft_atoi(&input[i]);
		else if (ft_strchr("cspdiuxX%", input[i]) && i != 0)
		{
			flags->type = input[i];
			break ;
		}
		i++;
	}
	if (flags->type == 0)
		return (0);
	return (i);
}
