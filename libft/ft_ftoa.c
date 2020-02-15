/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:01:32 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/15 20:14:03 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert(double f, int precision, int count, char *str)
{
	if (f * ft_exp(10, precision) >= 10)
	{
		convert(f / 10, precision, count + 1, str);
		str[count] = ((long)(f * ft_exp(10, precision)) % 10) + 48;
	}
	else
		str[count] = (long)(f * ft_exp(10, precision)) + 48;
}

char		*ft_ftoa(double f, int precision)
{
	char	*str;

	if (!(str = malloc(ft_nbrlen((long)f) + precision + 2)))
		return (NULL);
	convert(f, precision, 0, str);
	return (NULL);
}
