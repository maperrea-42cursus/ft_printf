/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 00:18:58 by maperrea          #+#    #+#             */
/*   Updated: 2021/09/02 00:18:47 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr_oct(t_tag tag, t_nbr n)
{
	if (tag.width != -1 && !(tag.flags & MINUS) &&
				(!(tag.flags & ZEROES) || tag.precision != -1))
		padding(n.width - n.size - ((tag.flags & HASHTAG) != 0), 0);
	if (tag.flags & HASHTAG)
		write(1, "0", 1);
	if ((tag.width != -1 && (tag.flags & ZEROES) &&
				!(tag.flags & MINUS)) && tag.precision == -1)
		padding(n.width - n.size - ((tag.flags & HASHTAG) != 0), 1);
	if (tag.precision != -1)
		padding(n.precision - ft_strlen(&(n.nbr)[n.neg]), 1);
	if (!(n.precision == 0 && ft_strlen(n.nbr) == 1 && *(n.nbr) == '0'))
		write(1, &(n.nbr)[n.neg], ft_strlen(&(n.nbr)[n.neg]));
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(n.width - n.size - ((tag.flags & HASHTAG) ? 2 : 0), 0);
}

int		print_oct(t_tag tag, va_list ap)
{
	t_nbr	n;

	n.width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	tag.precision = n.precision < 0 ? -1 : tag.precision;
	n.nbr = (*(tag.length))(ap, 1);
	tag.flags = ft_strlen(n.nbr) == 1 && *(n.nbr) == '0' ?
					tag.flags & ~HASHTAG : tag.flags;
	n.nbr = ft_convert_base(n.nbr, DEC_STR, OCT_STR);
	n.size = ft_strlen(n.nbr) > n.precision &&
		!(n.precision == 0 && ft_strlen(n.nbr) == 1 && *(n.nbr) == '0') ?
			ft_strlen(n.nbr) : n.precision;
	tag.flags = n.width < 0 && tag.width != -1 ? tag.flags | MINUS : tag.flags;
	n.width = n.width < 0 && tag.width != -1 ? -n.width : n.width;
	n.neg = 0;
	print_nbr_oct(tag, n);
	return (n.width > n.size + ((tag.flags & HASHTAG) != 0) ?
			n.width : n.size + ((tag.flags & HASHTAG) != 0));
}
