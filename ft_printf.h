/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:54:58 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/06/23 12:48:38 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define D "0123456789"
# define H "0123456789abcdef"
# define UH "0123456789ABCDEF"
# define O "01234567"

# include "libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		star;
	int		min_width;
	int		point;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	int		l;
	int		h;
	char	type;
}	t_flags;


/*
** ft_pritf Functions
*/
int		ft_printf(const char *fmt, ...);
int		set_params(char *input, t_flags *flags, va_list args);
void	handle_star(t_flags *flags, int arg);
int		handle_digit(t_flags *flags, char *input);
void	handle_minus(t_flags *flags);
void	handle_flags(char input, t_flags *flags, va_list args);
int		handle_lh(char *input, t_flags *flags);
int		get_case(t_flags *flags, va_list args, int *count);
int		case_c(t_flags *flags, va_list args);
int		case_s(t_flags *flags, va_list args);
int		case_p(t_flags *flags, va_list args);
int		case_d(t_flags *flags, va_list args);
int		case_i(t_flags *flags, va_list args);
int		case_u(t_flags *flags, va_list args);
int		case_x(t_flags *flags, va_list args);
int		case_percentage(t_flags *flags);
int		case_n(t_flags *flags, va_list args, int *count);
int		case_f(t_flags *flags, va_list args);
int		case_g(t_flags *flags, va_list args);
int		case_e(t_flags *flags, va_list args);
int		case_o(t_flags *flags, va_list args);
int		handle_width(t_flags *flags, int len);
char	*arg_conversions(t_flags *flags, va_list args);
char	*handle_number(t_flags *flags, char *nbr);
char	*handle_double(t_flags *flags, char *d);

/*
** Helper Functions
*/
int	ft_putchar(char c);
int	ft_putstr(char *str);
char	*ft_free_function(char *function, ...);
char	*ft_ftoa(long double d, int precision);
char	*ft_roundup_number(char *nbr);

#endif
