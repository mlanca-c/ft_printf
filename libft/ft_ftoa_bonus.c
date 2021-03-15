/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:45:42 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/03/15 20:09:57 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(double d)
{
	int		l;

	l = 0;
	if (d == 0)
		return (1);
	if (d < 0)
	{
		d *= -1;
		l++;
	}
	while (d > 0)
	{
		d /= 10;
		l++;
	}
	return (l);
}

char		*ft_ftoa(double d, int f)
{
	char	*s;
	char	*temp;
	char	*nbr;
	int		n;
	int		minus;

	minus = 0;
	if (d < 0)
	{
		minus = 1;
		d *= -1;
	}
	n = (int)d;
	s = ft_itoa(n);
	if (f != 0)
	{
		temp = s;
		s = ft_strjoin(s, ".");
		free(temp);
		nbr = ft_itoa((d - n) * ft_power(10, f));
		while (ft_strlen(nbr) < f)
		{
			temp = nbr;
			nbr = ft_strjoin("0", nbr);
			free(temp);
		}
		temp = s;
		s = ft_strjoin(s, nbr);
		free(temp);
		free(nbr);
	}
	if (minus)
	{
		temp = s;
		s = ft_strjoin("-", s);
		free(temp);
	}
	return (s);
}
