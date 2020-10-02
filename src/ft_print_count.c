/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:30:25 by maperrea          #+#    #+#             */
/*   Updated: 2020/10/02 17:30:47 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_count(t_tag tag, va_list ap)
{
	if (tag.width == -2)
		va_arg(ap, int);
	if (tag.precision == -2)
		va_arg(ap, int);
	return (0);
}
