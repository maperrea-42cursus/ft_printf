/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e_or_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:47:40 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/25 22:34:00 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		to_f(t_tag tag, t_nbr n)
{
	n.size = ft_strlen(ft_split(&(n.nbr[n.neg]), '.')[0]) + n.precision
		+ ((tag.flags & HASHTAG) || n.precision);
	return (print_float(tag, n));
}

int		to_e(t_tag tag, t_nbr n)
{
	n.size = 1 + n.precision + ((tag.flags & HASHTAG) || n.precision);
	return (print_exp(tag, n));
}

//TODO precision is the total number of digits to be printed
int		print_e_or_f(t_tag tag, va_list ap)
{
	t_nbr	n;
	t_nbr	n_dup;
	int		exp;

	n.nbr = ftoa(va_arg(ap, double));
	n.width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	n.precision = n.precision < 0 ? 6 : n.precision;
	n.neg = (*(n.nbr) == '-');
	tag.flags = n.width < 0 && tag.width != -1 ? tag.flags | MINUS : tag.flags;
	n.width = n.width < 0 && tag.width != -1 ? -n.width : n.width;
	if (!ft_isdigit(n.nbr[n.neg]))
		return (print_special(tag, n));
	n_dup = (t_nbr){ft_strdup(n.nbr), n.width, n.precision, 0, n.neg};
	exp = move_comma(&n_dup);
	exp += rounding(&n_dup);
	if (exp < -4 || exp >= n.precision)
		return(to_e(tag, n));
	else
		return(to_f(tag, n));
}
