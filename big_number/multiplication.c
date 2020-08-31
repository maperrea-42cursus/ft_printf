/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:09:00 by maperrea          #+#    #+#             */
/*   Updated: 2020/03/11 03:35:12 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_number.h"

static inline int	to_index(int x, t_big_number *yes)
{
	return (x >= 0 ? x : yes->decimal_size + x);
}

void				equalize_int(t_big_number *bn1, t_big_number *bn2)
{
	ft_realloc((void **)&bn2->int_part,
		bn2->int_size < 0 ? 0 : bn2->int_size,
		bn1->int_size < 0 ? 0 : bn1->int_size);
	bn2->int_size = bn1->int_size;
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

static inline void	compute_mult(t_big_number *out,
								t_big_number *bn1, t_big_number *bn2)
{
	unsigned int	tmp;
	int				i;
	int				j;
	int				k;

	i = bn1->decimal_size > 0 ? -bn1->decimal_size : 0;
	while (i < bn1->int_size)
	{
		j = bn2->decimal_size > 0 ? -bn2->decimal_size : 0;
		while (j < bn2->int_size)
		{
			(i + j >= 0 ? out->int_part : out->decimal_part)
	[to_index(i + j, out)] = (tmp =
	((i + j >= 0 ? out->int_part : out->decimal_part)[to_index(i + j, out)] +
	(i >= 0 ? bn1->int_part : bn1->decimal_part)[to_index(i, bn1)] *
	(j >= 0 ? bn2->int_part : bn2->decimal_part)[to_index(j, bn2)]));
			k = 0;
			while ((tmp /= (UCHAR_MAX + 1)) && ++k)
				(i + j + k >= 0 ? (out->int_part) : (out->decimal_part))
[to_index(i + j + k, out)] = (tmp += (i + j + k >= 0 ? (out->int_part) :
(out->decimal_part))[to_index(i + j + k, out)]);
			j++;
		}
		i++;
	}
}

t_big_number		*big_number_mult(t_big_number *bn1, t_big_number *bn2)
{
	t_big_number	*out;

	if (!(out = malloc(sizeof(t_big_number))))
		return (NULL);
	out->int_size = (bn1->int_size > 0 ? bn1->int_size : 0) +
					(bn2->int_size > 0 ? bn2->int_size : 0);
	out->decimal_size = (bn1->decimal_size > 0 ? bn1->decimal_size : 0) +
						(bn2->decimal_size > 0 ? bn2->decimal_size : 0);
	if (out->int_size > 0)
		if (!(out->int_part = ft_calloc(1, out->int_size)))
			return (NULL);
	if (out->decimal_size > 0)
		if (!(out->decimal_part = ft_calloc(1, out->decimal_size)))
			return (NULL);
	out->sign = bn1->sign ^ bn2->sign;
	equalize_num(bn1, bn2);
	compute_mult(out, bn1, bn2);
	return (out);
}
