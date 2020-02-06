/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:01:43 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/06 22:06:05 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(t_tag tag, va_list ap)
{
	char	c;
	int		width;

	width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	if (width < 0)
	{
		tag.flags = tag.flags & MINUS;
		width = -width;
	}
	c = va_arg(ap, int);
	if (tag.width != -1 && !(tag.flags & MINUS))
		padding(width - 1, 0);
	write(1, &c, 1);
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(width - 1, 0);
	return (tag.width == -1 ? 1 : width); 
}
