/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:21:47 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/09 20:14:02 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl				dbl_to_t_dbl(double n)
{
	t_dbl			dbl;
	unsigned char	*nbr;
	unsigned char	*tmp;

	nbr = (unsigned char *)&n;
	dbl.sign = nbr[7] >> 7;
	tmp = (unsigned char *)&(dbl.mantissa);
	ft_memcpy(tmp, nbr, 8);
	tmp[7] = 0;
	tmp[6] = tmp[6] & 0b00001111;
	dbl.exponent = 0;
	tmp = (unsigned char *)&(dbl.exponent);
	tmp[1] = (nbr[7] >> 4) & 0b00000111;
	tmp[0] = (nbr[7] << 4) | (nbr[6] >> 4);
	if (dbl.exponent)
	{
		dbl.mantissa |= 1l << 52;
		dbl.exponent -= 1023;
	}
	return (dbl);
}

char 	*positive_exponent(char *nbr, int exponent)
{
	int i;
	int len;

	if (!exponent)
		return (nbr);
	i = 1;
	nbr[0] += nbr[0] - '0';
	if (nbr[0] > '9')
	{
		nbr[0] -= 10;
		nbr = ft_strjoin("1", nbr);
		i++;
	}
	len = ft_strlen(nbr);
	while (i < len)
	{
		nbr[i] += nbr[i] - '0';
		if (nbr[i] > '9')
		{
			nbr[i] -= 10;
			(nbr[i - 1])++;
		}
		i++;
	}
	return (positive_exponent(nbr, exponent - 1));
}


char 	*negative_exponent(char *nbr, int exponent)
{
	int i;
	int dot_pos;

	if (!exponent)
		return (nbr);
	dot_pos = ft_strchr(nbr, '.');
	//printf("%d\n", dot_pos);
	i = ft_strlen(nbr) - 2;
	if ((nbr[i + 1] - '0') % 2)
		nbr = ft_strjoin(nbr, dot_pos == -1 ? ".5" : "5");
	nbr[i + 1] = ((nbr[i + 1] - '0') / 2) + '0';
	//printf("%s\n", nbr);
	while (i >= 0)
	{
		if (i == dot_pos)
			i--;
		if ((nbr[i] - '0') % 2)
			nbr[i + (i + 1 == dot_pos ? 2 : 1)] += 5;
		nbr[i] = ((nbr[i] - '0') / 2) + '0';
		i--;
	}
	if (nbr[0] == '0' && nbr[1] != '.')
		nbr = ft_strtrim(nbr, "0");
	return (negative_exponent(nbr, exponent + 1));
}

/*
** TODO special cases (NaN, +-inf, subnormals?)
** 		leaks on strjoin
*/
char	*ftoa (double nbr)
{
	char			*str;
	t_dbl			dbl;
	int				i;

	dbl = dbl_to_t_dbl(nbr);
	i = 52;
	dbl.mantissa <<= 1;
	while (!((dbl.mantissa >>= 1) & 1) && i)
		i--;
	dbl.exponent -= i;
	str = ft_utoa(dbl.mantissa);
	//printf("%s %d\n", str, dbl.exponent);
/*	if (dbl.exponent == 0)
		str = ft_strjoin(str, "."); */
	if (dbl.exponent > 0)
		str = positive_exponent(str, dbl.exponent);
	else if (dbl.exponent < 0)
		str = negative_exponent(str, dbl.exponent);
	if (dbl.sign)
		str = ft_strjoin("-", str);
	return (str);
}

