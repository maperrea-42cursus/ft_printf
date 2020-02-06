/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 02:44:58 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/06 21:33:08 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_regular(va_list ap, int u)
{
	char	*nbr;

	nbr = u ? ft_utoa(va_arg(ap, unsigned int)) : ft_itoa(va_arg(ap, int));
	return (nbr);
}

char	*get_short(va_list ap, int u)
{
	char	*nbr;

	nbr = u ? ft_utoa(va_arg(ap, unsigned int)) : ft_itoa(va_arg(ap, int));
	return (nbr);
}

char	*get_short_short(va_list ap, int u)
{
	char	*nbr;

	nbr = u ? ft_utoa(va_arg(ap, unsigned int)) : ft_itoa(va_arg(ap, int));
	return (nbr);
}

char	*get_long(va_list ap, int u)
{
	char	*nbr;

	nbr = u ? ft_utoa(va_arg(ap, unsigned long)) : ft_itoa(va_arg(ap, long));
	return (nbr);
}

char	*get_long_long(va_list ap, int u)
{
	char	*nbr;

	nbr = u ? ft_utoa(va_arg(ap, unsigned long long)) :
		ft_itoa(va_arg(ap, long long));
	return (nbr);
}
