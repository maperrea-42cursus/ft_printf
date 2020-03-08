/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:01:32 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/16 01:05:07 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convert(double f, int precision, int count, char *str)
{
	if (f * ft_exp(10, precision) >= 10)
	{
		if (count == precision)
			str[count++] = '.';
		str[count] = ((long)(f * ft_exp(10, precision)) % 10) + 48;
		convert(f / 10, precision, count + 1, str);
	}
	else
	{
		if (count == precision)
			str[count++] = '.';
		str[count] = (long)(f * ft_exp(10, precision)) + 48;
	}
	if (str[count] == 40)
		str[count] = 48;
}

char		*ft_ftoa(double f, int precision)
{
	char	*str;
	int len;
	int neg;

	if (f == 1.0/0.0)
		return (ft_strdup("inf"));
	if (f == -1.0/0.0)
		return (ft_strdup("-inf"));
	len = ft_nbrlen((long)f) + precision + 2;
	neg = 0;
	if (f < 0)
	{
		len++;
		neg = 1;
		f = -f;
	}
	if (!(str = malloc(len)))
		return (NULL);
	convert(f, precision, 0, str + (neg ? 1 : 0));
	str[len - 1] = 0;
	if (neg)
		str[0] = '-';
	str = ft_reverse_str(str);
	return (str);
}
