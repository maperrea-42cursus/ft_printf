/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:42:00 by maperrea          #+#    #+#             */
/*   Updated: 2020/10/02 13:49:24 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(t_tag tag, va_list ap)
{
	char	*str;
	int		width;
	int		precision;
	int		size;

	width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	tag.flags = width < 0 && tag.width != -1 ? tag.flags | MINUS : tag.flags;
	width = width < 0 && tag.width != -1 ? -width : width;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	size = ft_strlen(str) > precision && precision >= 0 ?
		precision : ft_strlen(str);
	if (tag.width != -1 && !(tag.flags & MINUS))
		padding(width - size, tag.flags & ZEROES ? 1 : 0);
	write(1, str, size);
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(width - size, 0);
	return (size > width ? size : width);
}
