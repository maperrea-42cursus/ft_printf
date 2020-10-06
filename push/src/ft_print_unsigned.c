/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 03:28:54 by maperrea          #+#    #+#             */
/*   Updated: 2020/10/02 16:39:09 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_unsigned(t_tag tag, va_list ap)
{
	t_nbr	n;

	n.width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	tag.precision = n.precision < 0 ? -1 : tag.precision;
	n.nbr = (*(tag.length))(ap, 1);
	n.size = ft_strlen(n.nbr) > n.precision &&
		!(n.precision == 0 && !ft_atoi(n.nbr)) ? ft_strlen(n.nbr) : n.precision;
	tag.flags = n.width < 0 && tag.width != -1 ? tag.flags | MINUS : tag.flags;
	n.width = n.width < 0 && tag.width != -1 ? -n.width : n.width;
	n.neg = 0;
	print_nbr(tag, n);
	return (n.width > n.size ? n.width : n.size + ((tag.flags & PLUS) >> 3));
}
