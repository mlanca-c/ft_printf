/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:45:42 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/16 11:39:54 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int  get_length(long double nb, int precision)
{
    int len;
    if (precision > 0)
        len = get_len_float(nb) + 1 + precision;
    else
        len = get_len_float(nb);
    return (len);
}

static void get_integral_part(char **str_nb,
        long double nb,
        int precision,
        int length)
{
    char    *tmp;
    if (nb >= LONG_MAX)
        tmp = ft_strdup("9223372036854775808");
    else
        tmp = ft_itoa(nb);
    if (-1 < nb && 1 / nb < 0)
    {
        **str_nb = '-';
        ft_strlcpy(*(str_nb) + 1, tmp, length - precision + 1);
    }
    else
        ft_strlcpy(*str_nb, tmp, length - precision + 1);
    free(tmp);
}

static void get_fractional_part(char **str_nb,
        long double *nb,
        int precision,
        int length)
{
    (*str_nb)[length - 1 - precision] = '.';
    while (precision-- > 0)
    {
        if (*nb == LONG_MIN || *nb >= LONG_MAX || ft_remainder(*nb, 1) == 0)
            (*str_nb)[length - 1 - precision] = '0';
        else
        {
            *nb *= 10;
            (*str_nb)[length - 1 - precision] = ft_abs(*nb) % 10 + '0';
        }
    }
}

static char *round_after_decimal(long double nb, int length, char *str_nb)
{
    long double remainder;
    int         i;
    i = length - 1;
    remainder = ft_remainder(nb * 10, 10);
    if (remainder < 5)
        return (str_nb);
    if (str_nb[i] != '9')
    {
        if (remainder == 5 && !ft_is_even(str_nb[i]))
            str_nb[i] += 1;
        else if (5 < remainder)
            str_nb[i] += 1;
        return (str_nb);
    }
    while (str_nb[i] == '9' && ft_strchr(str_nb, '.'))
        str_nb[i--] = '0';
    if (ft_isdigit(str_nb[i]) && str_nb[i] != '9' && ft_strchr(str_nb, '.'))
        str_nb[i] += 1;
    else
        str_nb = round_before_decimal(str_nb, length);
    return (str_nb);
}

char        *ft_ftoa(long double nb, int precision)
{
    int     length;
    char    *str_nb;
    length = get_length(nb, precision);
    str_nb = ft_calloc(length + 1, sizeof(char));
    if (!str_nb)
        return (0);
    get_integral_part(&str_nb, nb, precision, length);
    if (precision > 0)
        get_fractional_part(&str_nb, &nb, precision, length);
    if (!(nb == LONG_MIN || nb >= LONG_MAX))
        str_nb = round_after_decimal(nb, length, str_nb);
    return (str_nb);
}

int	main(void)
{
	printf("ft: %s\n", ft_ftoa(0.01234567890123456789012345678901));
	printf("c: %.16f\n", 0.01234567890123456789012345678901);
}
