/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 14:54:58 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/04 17:33:21 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include "stdarg.h"

typedef struct	s_flags
{
	int		minus;
	int		zero;
	int		star;
	int		min_width;
	int		point;
	int		precision;
	char	type;
}				t_flags;

int		ft_printf(const char *fmt, ...);
int		set_params(char *input, t_flags *flags);

#endif
