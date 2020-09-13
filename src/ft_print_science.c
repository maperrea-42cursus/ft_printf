/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_science.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:12:42 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/13 19:08:32 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		move_comma(t_nbr n)
{
	(void) n;
	return (0);
}
int		print_science(t_tag tag, va_list ap)
{
	t_nbr n;
	int exp;

	n.width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	n.precision = n.precision < 0 ? 6 : n.precision;
	n.nbr = ftoa(va_arg(ap, double));
	exp = move_comma(n);
	return (0);
}
