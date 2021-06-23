/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:04:26 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/18 18:09:18 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_double(t_flags *flags, char *d)
{
	if (flags->plus && !flags->zero)
		return (ft_free_function("ft_strjoin", " ", d, 2));
	else if (flags->space && !flags->zero)
		return (ft_free_function("ft_strjoin", "+", d, 2));
	return (d);
}
