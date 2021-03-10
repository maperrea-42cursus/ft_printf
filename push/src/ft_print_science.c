/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_science.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:12:42 by maperrea          #+#    #+#             */
/*   Updated: 2020/10/02 13:51:05 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		move_comma(t_nbr *n)
{
	int i;
	int ret_val;

	i = n->neg;
	ret_val = 0;
	if (n->nbr[n->neg] != '0')
	{
		while (n->nbr[i] != '.')
			i++;
		ret_val = i++ - (1 + n->neg);
		while (--i > 1 + n->neg)
			ft_memswap(n->nbr + i, n->nbr + i - 1, 1);
	}
	else if (ft_strlen(&n->nbr[n->neg]) > 2)
	{
		while (n->nbr[i] == '0' || n->nbr[i] == '.')
			i++;
		ret_val = -(i - (1 + n->neg));
		i = n->neg;
		while (++i < -(ret_val) + 1 + n->neg)
			ft_memswap(n->nbr + i, n->nbr + i + 1, 1);
		n->nbr = ft_strjoin(n->neg ? "-" : "",
						ft_strtrim(&n->nbr[n->neg], "0"));
	}
	return (ret_val);
}

int		print_exp(t_tag tag, t_nbr n, int exp)
{
	int padding_size;
	int exp_size;

	padding_size = n.width - n.size - ((tag.flags & (PLUS | SPACE)) || n.neg)
						- (exp_size = 2 + (exp >= 100 ? 3 : 2));
	if (tag.width != -1 && !(tag.flags & MINUS) && !(tag.flags & ZEROES))
		padding(padding_size, 0);
	n.neg ? write(1, "-", 1) : 0;
	!n.neg && (tag.flags & PLUS) ? write(1, "+", 1) : 0;
	!n.neg && !(tag.flags & PLUS) && (tag.flags & SPACE) ? write(1, " ", 1) : 0;
	if (tag.width != -1 && !(tag.flags & MINUS) && (tag.flags & ZEROES))
		padding(padding_size, 1);
	write(1, &(n.nbr[n.neg]), (n.size > ft_strlen(&(n.nbr[n.neg])) ?
				ft_strlen(&(n.nbr[n.neg])) : n.size));
	if (n.size > ft_strlen(&(n.nbr[n.neg])))
		padding(n.size - ft_strlen(&(n.nbr[n.neg])), 1);
	ft_printf("e%+03d", exp);
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(padding_size, 0);
	return (n.width > n.size + exp_size ?
		n.width : n.size + exp_size + (n.neg || (tag.flags & (PLUS | SPACE))));
}

int		print_science(t_tag tag, va_list ap)
{
	t_nbr	n;
	int		exp;

	n.width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	n.precision = n.precision < 0 ? 6 : n.precision;
	if (!(n.nbr = ftoa(va_arg(ap, double))))
		return (0);
	n.neg = (*(n.nbr) == '-');
	tag.flags = n.width < 0 && tag.width != -1 ? tag.flags | MINUS : tag.flags;
	n.width = n.width < 0 && tag.width != -1 ? -n.width : n.width;
	n.size = 1 + n.precision + ((tag.flags & HASHTAG) || n.precision);
	if (ft_isdigit(n.nbr[n.neg]))
	{
		exp = move_comma(&n);
		n.size -= rounding(&n);
		exp += move_comma(&n);
		return (print_exp(tag, n, exp));
	}
	else
		return (print_special(tag, n));
}
