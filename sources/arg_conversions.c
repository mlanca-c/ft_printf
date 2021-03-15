/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:13:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/15 17:13:29 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*handle_hh(t_flags *flags, va_list args)
{
	if ((flags->type == 'd' || flags->type == 'i'))
		return (ft_itoa((signed char)va_arg(args, int)));
	if (flags->type == 'x')
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned int), H));
	if (flags->type == 'X')
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned int), UH));
	if (flags->type == 'u')
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned int), D));
	return (0);
}

static char	*handle_h(t_flags *flags, va_list args)
{
	if ((flags->type == 'd' || flags->type == 'i'))
		return (ft_itoa((short int)va_arg(args, int)));
	if (flags->type == 'x')
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned int), H));
	if (flags->type == 'X')
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned int), UH));
	if (flags->type == 'u')
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned int), D));
	return (0);
}

static char	*handle_l(t_flags *flags, va_list args)
{
	if ((flags->type == 'd' || flags->type == 'i'))
		return (ft_llitoa((long int)va_arg(args, long int)));
	if (flags->type == 'x')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), H));
	if (flags->type == 'X')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), UH));
	if (flags->type == 'u')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), D));
	return (0);
}

static char	*handle_ll(t_flags *flags, va_list args)
{
	if ((flags->type == 'd' || flags->type == 'i'))
		return (ft_llitoa((long long)va_arg(args, long long)));
	if (flags->type == 'x')
		return (ft_llitoa_base(va_arg(args, unsigned long long), H));
	if (flags->type == 'X')
		return (ft_llitoa_base(va_arg(args, unsigned long long), UH));
	if (flags->type == 'u')
		return (ft_llitoa_base(va_arg(args, unsigned long long), D));
	return (0);
}

char		*arg_conversions(t_flags *flags, va_list args)
{
	if (flags->h == 1)
		return (handle_h(flags, args));
	if (flags->h == 2)
		return (handle_hh(flags, args));
	if (flags->l == 1 || flags->type == 'c')
		return (handle_l(flags, args));
	if (flags->l == 2)
		return (handle_ll(flags, args));
	if (flags->type == 's')
		return (va_arg(args, char *));
	if (flags->type == 'd' || flags->type == 'i')
		return (ft_itoa(va_arg(args, int)));
	if (flags->type == 'u')
		return (ft_itoa_base(va_arg(args, unsigned int), D));
	if (flags->type == 'x')
		return (ft_itoa_base(va_arg(args, unsigned int), H));
	if (flags->type == 'o')
		return (ft_itoa_base(va_arg(args, unsigned int), O));
	if (flags->type == 'X')
		return (ft_itoa_base(va_arg(args, unsigned int), UH));
	if (flags->type == 'p')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), H));
	return (NULL);
}
