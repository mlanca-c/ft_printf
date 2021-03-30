/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:39:04 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/30 10:56:28 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*handle_space(t_flags *flags, char *nbr)
{
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
	nbr = ft_free_function("ft_strjoin", " ", nbr, 2);
	return (nbr);
}

static char	*handle_positive(t_flags *flags, char *nbr)
{
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
	nbr = ft_free_function("ft_strjoin", "+", nbr, 2);
	return (nbr);
}

static char	*handle_negative(t_flags *flags, char *nbr)
{
	nbr = ft_free_function("ft_substr", nbr, 1, (int)ft_strlen(nbr));
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
	nbr = ft_free_function("ft_strjoin", "-", nbr, 2);
	return (nbr);
}

static char	*handle_hash(t_flags *flags, char *nbr)
{
	if (flags->type == 'x' || flags->type == 'X')
		nbr = ft_free_function("ft_substr", nbr, 2, (int)ft_strlen(nbr));
	if (flags->type == 'o')
		nbr = ft_free_function("ft_substr", nbr, 1, (int)ft_strlen(nbr));
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
	if (flags->type == 'x' && !flags->zero)
		nbr = ft_free_function("ft_strjoin", "0x", nbr, 2);
	else if (flags->type == 'X' && !flags->zero)
		nbr = ft_free_function("ft_strjoin", "0X", nbr, 2);
	else if (flags->type == 'o' && !flags->zero)
		nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
	return (nbr);
}

char	*handle_number(t_flags *flags, char *nbr)
{
	if (!ft_strncmp(nbr, "0", 2) && flags->point && !flags->precision)
		nbr = ft_free_function("ft_strdup", nbr, "");
	if (nbr[0] == '-')
		return (handle_negative(flags, nbr));
	else if (flags->hash && (flags->type == 'x' || flags->type == 'X'
			|| flags->type == 'o'))
		return (handle_hash(flags, nbr));
	else if (flags->plus && !flags->zero)
		return (handle_positive(flags, nbr));
	else if (flags->space && !flags->zero)
		return (handle_space(flags, nbr));
	while (flags->precision > (int)ft_strlen(nbr))
		nbr = ft_free_function("ft_strjoin", "0", nbr, 2);
	return (nbr);
}
