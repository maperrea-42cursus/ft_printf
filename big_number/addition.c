/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 04:19:59 by maperrea          #+#    #+#             */
/*   Updated: 2020/03/11 03:04:39 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_number.h"

static inline int	compute_add(t_bn_part *out, t_bn_part *bn1, t_bn_part *bn2)
{
	unsigned char	carry_bit;
	int				tmp;
	int				i;

	if (out->size <= 0)
		return (0);
	carry_bit = 0;
	i = 0;
	while (i < bn1->size || i < bn2->size)
	{
		out->part[i] =
				(tmp = out->part[i] + carry_bit +
				(i < bn1->size ? bn1->part[i] : 0) +
				(i < bn2->size ? bn2->part[i] : 0));
		if (tmp > UCHAR_MAX)
			carry_bit = 1;
		else
			carry_bit = 0;
		i++;
	}
	return (carry_bit);
}

void				equalize_dec(t_big_number *bn1, t_big_number *bn2)
{
	int i;
	int diff;

	ft_realloc((void **)&bn2->decimal_part,
			bn2->decimal_size < 0 ? 0 : bn2->decimal_size,
			bn1->decimal_size < 0 ? 0 : bn1->decimal_size);
	i = bn2->decimal_size;
	diff = bn1->decimal_size - bn2->decimal_size;
	while (i >= 0)
	{
		bn2->decimal_part[i + diff] = bn2->decimal_part[i];
		i--;
	}
	while (i + diff >= 0)
	{
		bn2->decimal_part[i + diff] = 0;
		i--;
	}
	bn2->decimal_size = bn1->decimal_size;
}

static inline void	equalize_num(t_big_number *bn1, t_big_number *bn2)
{
	if (bn1->decimal_size > bn2->decimal_size)
		equalize_dec(bn1, bn2);
	else if (bn2->decimal_size > bn1->decimal_size)
		equalize_dec(bn2, bn1);
}

static inline void	carry(t_big_number *out, int flag)
{
	if (flag)
	{
		if (out->int_size <= 0)
		{
			if (!(out->int_part = malloc(1)))
				return ;
			out->int_size = 1;
		}
		out->int_part[0] += 1;
	}
	else
	{
		ft_realloc((void **)&out->int_part, out->int_size, out->int_size + 1);
		out->int_part[out->int_size] = 1;
		out->int_size++;
	}
}

t_big_number		*big_number_add(t_big_number *bn1, t_big_number *bn2)
{
	t_big_number	*out;

	if (!(out = malloc(sizeof(t_big_number))))
		return (NULL);
	out->int_size = bn1->int_size > bn2->int_size ?
		bn1->int_size : bn2->int_size;
	out->decimal_size = bn1->decimal_size > bn2->decimal_size ?
		bn1->decimal_size : bn2->decimal_size;
	if (out->int_size > 0)
		if (!(out->int_part = ft_calloc(1, out->int_size)))
			return (NULL);
	if (out->decimal_size > 0)
		if (!(out->decimal_part = ft_calloc(1, out->decimal_size)))
			return (NULL);
	equalize_num(bn1, bn2);
	if (compute_add(&(t_bn_part){out->decimal_part, out->decimal_size},
					&(t_bn_part){bn1->decimal_part, bn1->decimal_size},
					&(t_bn_part){bn2->decimal_part, bn2->decimal_size}))
		carry(out, 1);
	if (compute_add(&(t_bn_part){out->int_part, out->int_size},
					&(t_bn_part){bn1->int_part, bn1->int_size},
					&(t_bn_part){bn2->int_part, bn2->int_size}))
		carry(out, 0);
	return (out);
}
