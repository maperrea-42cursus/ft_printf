/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 18:52:26 by maperrea          #+#    #+#             */
/*   Updated: 2020/03/11 03:14:11 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_number.h"

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

static inline void	int_part(t_big_number *big_num, t_dbl dbl)
{
	unsigned long tmp;

	if (big_num->int_size <= 0)
	{
		big_num->int_part = NULL;
		return ;
	}
	if (!(big_num->int_part = ft_calloc(1, big_num->int_size)))
		return ;
	tmp = dbl.exponent > 52 ? dbl.mantissa << ((dbl.exponent - 52) % 8) :
		dbl.mantissa >> -(dbl.exponent - 52);
	ft_memcpy(big_num->int_part + (dbl.exponent > 52 ?
				((dbl.exponent - 52) / 8) : 0), &tmp,
			big_num->int_size > 8 ? 8 : big_num->int_size);
}

static inline void	dec_part(t_big_number *big_num, t_dbl dbl)
{
	unsigned long tmp;

	if (big_num->decimal_size <= 0)
	{
		big_num->decimal_part = NULL;
		return ;
	}
	if (!(big_num->decimal_part = ft_calloc(1, big_num->decimal_size)))
		return ;
	if (dbl.exponent >= 0)
		tmp = (dbl.mantissa << (11 + dbl.exponent + 1))
			>> (64 - (8 * big_num->decimal_size));
	else
	{
		tmp = dbl.mantissa << (11 - ((-dbl.exponent - 1) % 4));
		if ((-dbl.exponent - 1) % 8 >= 4 && dbl.exponent < 0)
			tmp >>= 4;
		while (!((tmp >>= 8) & 0b11111111) && tmp)
			;
	}
	ft_memcpy(big_num->decimal_part, &tmp,
			big_num->decimal_size > 8 ? 8 : big_num->decimal_size);
}

t_big_number		*dbl_to_bn(double n)
{
	t_big_number	*big_num;
	t_dbl			dbl;
	unsigned long	tmp;
	int				decimal_bits;

	dbl = dbl_to_t_dbl(n);
	if (!(big_num = malloc(sizeof(t_big_number))))
		return (NULL);
	big_num->sign = dbl.sign;
	tmp = dbl.mantissa << 1;
	decimal_bits = 52;
	while (!((tmp >>= 1) & 1) && decimal_bits)
		decimal_bits--;
	big_num->int_size = ((dbl.exponent + 1) / 8) +
		((dbl.exponent + 1) % 8 && dbl.exponent >= 0 && n ? 1 : 0);
	int_part(big_num, dbl);
	big_num->decimal_size = ((decimal_bits - dbl.exponent) / 8) +
		((decimal_bits - dbl.exponent) % 8 ? 1 : 0);
	dec_part(big_num, dbl);
	return (big_num);
}
