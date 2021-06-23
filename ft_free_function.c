/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:46:12 by mlanca-c          #+#    #+#             */
/*   Updated: 2021/06/23 12:52:32 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_free_function(char *function, ...)
{
	va_list	args;
	char	*temp;
	char	*str;
	char	*second;

	va_start(args, function);
	str = va_arg(args, char *);
	temp = str;
	if (!ft_strncmp(function, "ft_strdup", ft_strlen(function)))
		str = ft_strdup(va_arg(args, char *));
	else if (!ft_strncmp(function, "ft_strjoin", ft_strlen(function)))
	{
		second = va_arg(args, char *);
		if (va_arg(args, int) == 1)
			temp = str;
		else
			temp = second;
		str = ft_strjoin(str, second);
	}
	else if (!ft_strncmp(function, "ft_substr", ft_strlen(function)))
		str = ft_substr(str, va_arg(args, int), va_arg(args, int));
	free(temp);
	return (str);
}
