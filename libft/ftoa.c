/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 15:21:47 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/08 19:16:19 by maperrea         ###   ########.fr       */
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
	return NULL;
}


char 	*negative_exponent(char *nbr, int exponent)
{
	return NULL;
}

/*
** TODO special cases (NaN, +-inf, subnormals?)
*/
char	*ftoa (double nbr)
{
	char			*int_part;
	t_dbl			dbl;
	int				i;

	dbl = dbl_to_t_dbl(nbr);
	i = 52;
	dbl.mantissa <<= 1;
	while (!((dbl.mantissa >>= 1) & 1) && i)
		i--;
	dbl.exponent -= i;
	printf(">>%ld, %d\n", dbl.mantissa, dbl.exponent);
	int_part = ft_utoa(dbl.mantissa);
	return(int_part);
}

