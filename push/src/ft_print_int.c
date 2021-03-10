/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:08:37 by maperrea          #+#    #+#             */
/*   Updated: 2020/10/02 16:39:00 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr(t_tag tag, t_nbr n)
{
	if (tag.width != -1 && !(tag.flags & MINUS) &&
				(!(tag.flags & ZEROES) || tag.precision != -1))
		padding(n.width - n.size - ((tag.flags & (PLUS | SPACE)) || n.neg), 0);
	n.neg ? write(1, "-", 1) : 0;
	!n.neg && (tag.flags & PLUS) ? write(1, "+", 1) : 0;
	!n.neg && !(tag.flags & PLUS) && (tag.flags & SPACE) ? write(1, " ", 1) : 0;
	if ((tag.width != -1 && (tag.flags & ZEROES) &&
				!(tag.flags & MINUS)) && tag.precision == -1)
		padding(n.width - n.size - ((tag.flags & (PLUS | SPACE)) || n.neg), 1);
	if (tag.precision != -1)
		padding(n.precision - ft_strlen(&(n.nbr)[n.neg]), 1);
	if (!(n.precision == 0 && !ft_atoi(n.nbr)))
		write(1, &(n.nbr)[n.neg], ft_strlen(&(n.nbr)[n.neg]));
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(n.width - n.size - ((tag.flags & (PLUS | SPACE)) || n.neg), 0);
}

int		print_int(t_tag tag, va_list ap)
{
	t_nbr	n;

	n.width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	tag.precision = n.precision < 0 ? -1 : tag.precision;
	if (!(n.nbr = (*(tag.length))(ap, 0)))
		return (0);
	n.neg = (*(n.nbr) == '-');
	n.size = ft_strlen(&(n.nbr)[n.neg]) > n.precision && !(n.precision == 0
		&& !ft_atoi(n.nbr)) ? ft_strlen(&(n.nbr)[n.neg]) : n.precision;
	tag.flags = n.width < 0 && tag.width != -1 ? tag.flags | MINUS : tag.flags;
	n.width = n.width < 0 && tag.width != -1 ? -n.width : n.width;
	print_nbr(tag, n);
	return (n.width > n.size ?
			n.width : n.size + (n.neg || (tag.flags & (PLUS | SPACE))));
}
