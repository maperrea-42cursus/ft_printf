/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:04:36 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/11 19:24:57 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_float(t_tag tag, t_nbr n)
{
	if (tag.width != -1 && !(tag.flags & MINUS) && !(tag.flags & ZEROES))
		padding(n.width - n.size
				- ((tag.flags & (PLUS | SPACE)) || n.neg ? 1 : 0), 0);
	n.neg ? write(1, "-", 1) : 0;
	!n.neg && (tag.flags & PLUS) ? write(1, "+", 1) : 0;
	!n.neg && !(tag.flags & PLUS) && (tag.flags & SPACE) ? write(1, " ", 1) : 0;
	if (tag.width != -1 && !(tag.flags & MINUS) && (tag.flags & ZEROES))
		padding(n.width - n.size
				- ((tag.flags & (PLUS | SPACE)) || n.neg ? 1 : 0), 1);
	write(1, &(n.nbr[n.neg]), (n.size > ft_strlen(&(n.nbr[n.neg])) ?
			ft_strlen(&(n.nbr[n.neg])) : n.size));
	if ((!n.precision && (tag.flags & HASHTAG) && n.nbr[n.size - 1] != '.')
			|| (n.precision && ft_strchr(n.nbr, '.') == -1))
		write(1, ".", 1);
	if (n.size > ft_strlen(&(n.nbr[n.neg])) + ((tag.flags & HASHTAG) ? 1 : 0))
		padding(n.size - ft_strlen(&(n.nbr[n.neg])), 1);
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(n.width - n.size
				- ((tag.flags & (PLUS | SPACE)) || n.neg ? 1 : 0), 0);
}

int		print_double(t_tag tag, va_list ap)
{
	t_nbr	n;

	n.width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	n.precision = n.precision < 0 ? 6 : n.precision;
	n.nbr = ftoa(va_arg(ap, double));
	n.neg = *(n.nbr) == '-' ? 1 : 0;
	tag.flags = n.width < 0 && tag.width != -1 ? tag.flags | MINUS : tag.flags;
	n.width = n.width < 0 && tag.width != -1 ? -n.width : n.width;
	n.size = ft_strlen(ft_split(&(n.nbr[n.neg]), '.')[0]) + n.precision +
		((tag.flags & HASHTAG) || n.precision ? 1 : 0);
	print_float(tag, n);
	return (ft_strlen(n.nbr));
}
