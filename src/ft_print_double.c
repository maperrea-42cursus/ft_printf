/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:04:36 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/23 18:29:41 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_double(t_tag tag, va_list ap)
{
	t_nbr	n;

	n.width = tag.width = -2 ? va_arg(ap, int) : tag.width;
	tag.precision = tag.precision == -1 ? 6 : tag.precision;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	n.nbr = ft_ftoa(va_arg(ap, double), n.precision);
	n.neg = *(n.nbr) == '-' ? 1 : 0;
	write(1, n.nbr, ft_strlen(n.nbr) - (!n.precision ? 1 : 0));
	return (ft_strlen(n.nbr));
}
