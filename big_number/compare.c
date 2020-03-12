/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:23:31 by maperrea          #+#    #+#             */
/*   Updated: 2020/03/11 03:14:55 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_number.h"

/*
** return 1 if bn1 > bn2, -1 if bn2 > bn1, 0 if bn1 == bn2
*/

static int	memrevcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	size_t			i;

	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	i = n;
	while (i > 0)
	{
		if (cs1[i - 1] != cs2[i - 1])
			return ((int)(cs1[i - 1] - cs2[i - 1]));
		i--;
	}
	return (0);
}

int			bn_compare(t_big_number *bn1, t_big_number *bn2)
{
	int diff;

	if (bn1->int_size > 0 && bn1->int_size > bn2->int_size)
		return (1);
	if (bn2->int_size > 0 && bn2->int_size > bn1->int_size)
		return (-1);
	if (bn1->int_size > 0 && bn2->int_size > 0 &&
			(diff = memrevcmp(bn1->int_part, bn2->int_part, bn1->int_size)))
		return (diff > 0 ? 1 : -1);
	if (bn1->decimal_size <= 0 && bn2->decimal_size <= 0)
		return (0);
	if (bn1->decimal_size <= 0 || bn2->decimal_size <= 0)
		return (bn1->decimal_size > 0 ? 1 : -1);
	if (bn1->decimal_size == bn2->decimal_size)
	{
		if ((diff = memrevcmp(bn1->decimal_part,
						bn2->decimal_part, bn1->decimal_size)))
			return (diff > 0 ? 1 : -1);
		return (0);
	}
	diff = memrevcmp(bn1->decimal_part, bn2->decimal_part,
bn1->decimal_size > bn2->decimal_size ? bn2->decimal_size : bn1->decimal_size);
	if (!diff)
		return (bn1->decimal_size > bn2->decimal_size ? 1 : -1);
	return (diff > 0 ? 1 : -1);
}
