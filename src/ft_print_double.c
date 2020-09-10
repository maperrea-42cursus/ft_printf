/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:04:36 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/10 20:49:42 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_float(t_tag tag, t_nbr nbr)
{
	
}

int		print_double(t_tag tag, va_list ap)
{
	t_nbr	n;

	n.width = tag.width = -2 ? va_arg(ap, int) : tag.width;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	tag.precision = n.precision < 0 ? 6 : tag.precision;
	n.nbr = ftoa(va_arg(ap, double));
	n.neg = *(n.nbr) == '-' ? 1 : 0;
	n.size = ft_strlen(ft_split(n.nbr, '.')[0]) + n.precision +
		((tag.flags & HASHTAG) || n.precision ? 1 : 0);
	tag.flags = n.width < 0 && tag.width != -1 ? tag.flags | MINUS : tag.flags;
	n.width = n.width < 0 && tag.width != -1 ? -n.width : n.width;
	return (ft_strlen(n.nbr));
}
