/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:39:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/13 20:50:03 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*handle_negative(t_flags *flags, char *nbr)
{
	nbr = ft_free_function("ft_substr", nbr, 1, (int)ft_strlen(nbr));
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", nbr, "0");
	nbr = ft_free_function("ft_strjoin", nbr, "-");
	return (nbr);
}

char	*handle_number(t_flags *flags, char *nbr)
{
	if (!ft_strncmp(nbr, "0", 1) && flags->point && !flags->precision)
		nbr = ft_free_function("ft_strdup", nbr, "");
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", nbr, "0");
	return (nbr);
}
