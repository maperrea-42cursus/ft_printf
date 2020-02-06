/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:42:00 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/06 22:26:10 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(t_tag tag, va_list ap)
{
	char	*str;
	int		width;
	int		precision;
	int 	size;

	width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	str = va_arg(ap, char *);
	size = (int)ft_strlen(str) > precision && precision != -1 ? 
			precision : (int)ft_strlen(str);
	if (width < 0)
	{
		tag.flags = tag.flags & MINUS;
		width = -width;
	}
	if (tag.width != -1 && !(tag.flags & MINUS))
		padding(width - size, 0);
	write(1, str, size);
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(width - size, 0);
	return (size > width ? size : width);
}
