/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_conversions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:13:41 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/30 10:30:15 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*handle_h(t_flags *flags, va_list args)
{
	if (flags->h == 2 && (flags->type == 'd' || flags->type == 'i'))
		return (ft_itoa((signed char)va_arg(args, int)));
	if (flags->h == 2 && flags->type == 'x')
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned int), H));
	if (flags->h == 2 && flags->type == 'X')
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned int), UH));
	if (flags->h == 2 && flags->type == 'u')
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned int), D));
	if (flags->h == 2 && flags->type == 'o')
		return (ft_itoa_base((unsigned char)va_arg(args, unsigned int), O));
	if (flags->h == 1 && (flags->type == 'd' || flags->type == 'i'))
		return (ft_itoa((short int)va_arg(args, int)));
	if (flags->h == 1 && flags->type == 'x')
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned int), H));
	if (flags->h == 1 && flags->type == 'X')
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned int), UH));
	if (flags->h == 1 && flags->type == 'u')
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned int), D));
	if (flags->h == 1 && flags->type == 'o')
		return (ft_itoa_base((unsigned short)va_arg(args, unsigned int), O));
	return (0);
}

static char	*handle_l(t_flags *flags, va_list args)
{
	if (flags->l == 1 && (flags->type == 'd' || flags->type == 'i'))
		return (ft_llitoa((long int)va_arg(args, long int)));
	if (flags->l == 1 && flags->type == 'x')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), H));
	if (flags->l == 1 && flags->type == 'X')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), UH));
	if (flags->l == 1 && flags->type == 'u')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), D));
	if (flags->l == 1 && flags->type == 'o')
		return (ft_llitoa_base((unsigned long)va_arg(args, unsigned long), O));
	if (flags->l == 2 && (flags->type == 'd' || flags->type == 'i'))
		return (ft_llitoa((long long)va_arg(args, long long)));
	if (flags->l == 2 && flags->type == 'x')
		return (ft_llitoa_base(va_arg(args, unsigned long long), H));
	if (flags->l == 2 && flags->type == 'X')
		return (ft_llitoa_base(va_arg(args, unsigned long long), UH));
	if (flags->l == 2 && flags->type == 'u')
		return (ft_llitoa_base(va_arg(args, unsigned long long), D));
	if (flags->l == 2 && flags->type == 'o')
		return (ft_llitoa_base(va_arg(args, unsigned long long), O));
	return (0);
}

char	*arg_conversions(t_flags *flags, va_list args)
{
	if (flags->h)
		return (handle_h(flags, args));
	if (flags->l)
		return (handle_l(flags, args));
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
