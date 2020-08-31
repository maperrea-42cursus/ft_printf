/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:58:00 by maperrea          #+#    #+#             */
/*   Updated: 2020/03/16 17:58:00 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_number.h"

void		bn_trim(t_big_number *bn)
{
	int i;
	int j;

	i = bn->int_size - 1;
	while (i >= 0 && !bn->int_part[i])
		i--;
	if (i < bn->int_size - 1)
	{
		ft_realloc((void **)&(bn->int_part), bn->int_size, i + 1);
		bn->int_size = i + 1;
	}
	i = 0;
	j = 0;
	while (i < bn->decimal_size && !bn->decimal_part[i])
		i++;
	if (i)
	{
		while (i < bn->decimal_size)
		{
			bn->decimal_part[j] = bn->decimal_part[i];
			i++;
			j++;
		}
		ft_realloc((void **)&(bn->decimal_part), bn->decimal_size, j);
		bn->decimal_size = j;
	}
}
