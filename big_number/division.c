/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 10:15:00 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/08 16:52:31 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "big_number.h"

static inline int	to_index(int x, t_big_number *yes)
{
	return (x >= 0 ? x : yes->decimal_size + x);
}

static inline void	equalize_num(t_big_number *bn1, t_big_number *bn2)
{
	if (bn1->int_size > bn2->int_size)
		equalize_int(bn1, bn2);
	else if (bn1->int_size < bn2->int_size)
		equalize_int(bn2, bn1);
	if (bn1->decimal_size > bn2->decimal_size)
		equalize_dec(bn1, bn2);
	else if (bn2->decimal_size > bn1->decimal_size)
		equalize_dec(bn2, bn1);
}

static inline void compute_div(t_big_number *out, t_big_number *bn1, 
								t_big_number *bn2, int precision)
{
	
}

t_big_number		*big_number_div(t_big_number *bn1, t_big_number *bn2,
									int precision)
{
	t_big_number *out;

	if (!(out = malloc(sizeof(t_big_number))))
		return (NULL);
	//TODO size can be optimized
	out->int_size = (bn1->int_size > 0 ? bn1->int_size : 0) +
					(bn2->decimal_size > 0 ? bn2->decimal_size : 0) + 1;
	out->decimal_size = precision;
	if (out->int_size > 0)
		if (!(out->int_part = ft_calloc(1, out->int_size)))
			return (NULL);
	if (out->decimal_size > 0)
		if (!(out->decimal_part = ft_calloc(1, out->decimal_size)))
			return (NULL);
	out->sign = bn1->sign ^ bn2->sign;
	equalize_num(bn1, bn2);
	compute_div(out, bn1, bn2, precision);
	return (out);
}
*/
