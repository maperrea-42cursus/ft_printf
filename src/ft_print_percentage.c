/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percentage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:33:36 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/27 21:23:48 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percentage(t_tag tag, va_list ap)
{
	int		width;

	width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	tag.precision == -2 ? va_arg(ap, int) : 0;
	if (width < 0)
	{
		tag.flags = tag.flags | MINUS;
		width = -width;
	}
	if (tag.width != -1 && !(tag.flags & MINUS))
		padding(width - 1, (tag.flags & ZEROES) ? 1 : 0);
	write(1, "%", 1);
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(width - 1, 0);
	return (tag.width == -1 ? 1 : width); 
}
