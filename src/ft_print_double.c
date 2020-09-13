/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:04:36 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/13 19:08:04 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rounding(t_nbr *n)
{
	int value;
	int i;

	if ((i = ft_strchr(n->nbr, '.') + n->precision + 1) >= ft_strlen(n->nbr))
		return ;
	value = n->nbr[i] - 48;
	while (value == 5 && n->nbr[++i])
		value += n->nbr[i] - 48;
	i = ft_strchr(n->nbr, '.') + n->precision;
	if (value > 5 || (value == 5 && n->nbr[i] == '.' && n->nbr[i - 1] == '9'))
	{
		while (i >= n->neg && (n->nbr[i] == '9' || n->nbr[i] == '.'))
			if (n->nbr[i--] == '9')
				n->nbr[i + 1] = '0';
		if (i < n->neg)
		{
			n->nbr = ft_strjoin(n->neg ? "-1" : "1", &(n->nbr[n->neg]));
			n->size++;
		}
		else
			n->nbr[i] += 1;
	}
	else if (value == 5 && n->nbr[i] == '.')
		n->nbr[i - 1] += (n->nbr[i - 1] - '0') % 2;
	return ;
}

int		print_special(t_tag tag, t_nbr n)
{
	if (!ft_strncmp(n.nbr, "nan", 3))
		tag.flags = tag.flags & ~PLUS & ~SPACE;
	if (tag.width != -1 && !(tag.flags & MINUS))
		padding(n.width - 3 - ((tag.flags & (PLUS | SPACE)) || n.neg), 0);
	n.neg ? write(1, "-", 1) : 0;
	!n.neg && (tag.flags & PLUS) ? write(1, "+", 1) : 0;
	!n.neg && !(tag.flags & PLUS) && (tag.flags & SPACE) ? write(1, " ", 1) : 0;
	write(1, &(n.nbr[n.neg]), 3);
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(n.width - 3 - ((tag.flags & (PLUS | SPACE)) || n.neg), 0);
	return (n.width > 3 ?
			n.width : 3 + (n.neg || (tag.flags & (PLUS | SPACE))));
}

int		print_float(t_tag tag, t_nbr n)
{
	rounding(&n);
	if (tag.width != -1 && !(tag.flags & MINUS) && !(tag.flags & ZEROES))
		padding(n.width - n.size - ((tag.flags & (PLUS | SPACE)) || n.neg), 0);
	n.neg ? write(1, "-", 1) : 0;
	!n.neg && (tag.flags & PLUS) ? write(1, "+", 1) : 0;
	!n.neg && !(tag.flags & PLUS) && (tag.flags & SPACE) ? write(1, " ", 1) : 0;
	if (tag.width != -1 && !(tag.flags & MINUS) && (tag.flags & ZEROES))
		padding(n.width - n.size - ((tag.flags & (PLUS | SPACE)) || n.neg), 1);
	write(1, &(n.nbr[n.neg]), (n.size > ft_strlen(&(n.nbr[n.neg])) ?
			ft_strlen(&(n.nbr[n.neg])) : n.size));
	if (n.size > ft_strlen(&(n.nbr[n.neg])))
		padding(n.size - ft_strlen(&(n.nbr[n.neg])), 1);
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(n.width - n.size - ((tag.flags & (PLUS | SPACE)) || n.neg), 0);
	return (n.width > n.size ?
			n.width : n.size + (n.neg || (tag.flags & (PLUS | SPACE))));
}

int		print_double(t_tag tag, va_list ap)
{
	t_nbr	n;

	n.width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	n.precision = n.precision < 0 ? 6 : n.precision;
	n.nbr = ftoa(va_arg(ap, double));
	n.neg = (*(n.nbr) == '-');
	tag.flags = n.width < 0 && tag.width != -1 ? tag.flags | MINUS : tag.flags;
	n.width = n.width < 0 && tag.width != -1 ? -n.width : n.width;
	n.size = ft_strlen(ft_split(&(n.nbr[n.neg]), '.')[0]) + n.precision
		+ ((tag.flags & HASHTAG) || n.precision);
	if (ft_isdigit(n.nbr[0]) || (n.nbr[0] == '-' && ft_isdigit(n.nbr[1])))
		return (print_float(tag, n));
	else
		return (print_special(tag, n));
}
