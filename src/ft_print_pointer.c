/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:26:19 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/13 17:16:49 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_pointer(t_tag tag, va_list ap)
{
	tag.flags = tag.flags | HASHTAG;
	tag.length = &get_long_long;
	return(print_hex(tag, ap));
}
