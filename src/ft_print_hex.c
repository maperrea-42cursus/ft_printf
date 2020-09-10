/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_lc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:40:58 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/10 20:49:38 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr_hex(t_tag tag, t_nbr n)
{	
	if (tag.width != -1 && !(tag.flags & MINUS) &&
				(!(tag.flags & ZEROES) || tag.precision != -1))
		padding(n.width - n.size - (tag.flags & HASHTAG ? 2 : 0), 0);
	(tag.flags & HASHTAG) && (tag.specifier == HEX_LC ||
							tag.specifier == POINTER) ? write(1, "0x", 2) : 0;
	(tag.flags & HASHTAG) && tag.specifier == HEX_UC ? write(1, "0X", 2) : 0;
	if ((tag.width != -1 && (tag.flags & ZEROES) &&
				!(tag.flags & MINUS)) && tag.precision == -1)
		padding(n.width - n.size - (tag.flags & HASHTAG ? 2 : 0), 1);
	if (tag.precision != -1) 
		padding(n.precision - ft_strlen(&(n.nbr)[n.neg]), 1);
	if (!(n.precision == 0 && ft_strlen(n.nbr) == 1 && *(n.nbr) == '0'))
		write(1, &(n.nbr)[n.neg], ft_strlen(&(n.nbr)[n.neg]));
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(n.width - n.size - (tag.flags & HASHTAG ? 2 : 0), 0);
}

int		print_hex(t_tag tag, va_list ap)
{
	t_nbr	n;
	char	*tmp;

	n.width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	tag.precision = n.precision < 0 ? -1 : tag.precision;
	n.nbr = (*(tag.length))(ap, 1);
	tmp = n.nbr;
	tag.flags = ft_strlen(n.nbr) == 1 && *(n.nbr) == '0' &&
		!(tag.specifier == POINTER) ? tag.flags & ~HASHTAG : tag.flags;
	if (tag.specifier == HEX_UC)
		n.nbr = ft_convert_base(n.nbr, DEC_STR, HEX_UC_STR);
	else
		n.nbr = ft_convert_base(n.nbr, DEC_STR, HEX_LC_STR);
	free(tmp);
	n.size = ft_strlen(n.nbr) > n.precision &&
		!(n.precision == 0 && ft_strlen(n.nbr) == 1 && *(n.nbr) == '0') ?
			ft_strlen(n.nbr) : n.precision;
	tag.flags = n.width < 0 && tag.width != -1 ? tag.flags | MINUS : tag.flags;
	n.width = n.width < 0 &&tag.width != -1 ? -n.width : n.width;
	n.neg = 0;
	print_nbr_hex(tag, n);
	free(n.nbr);
	return (n.width > n.size + (tag.flags & HASHTAG) ?
			n.width : n.size + (tag.flags & HASHTAG));
}
