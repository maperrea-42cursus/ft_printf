/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 14:04:36 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/13 00:03:31 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
void	print_float(t_tag tag, t_nbr n)
{
	if (tag.width != -1 && !(tag.flags & MINUS) && !(tag.flags & ZEROES))
		padding(n.width - n.size
				- ((tag.flags & (PLUS | SPACE)) || n.neg), 0);
	n.neg ? write(1, "-", 1) : 0;
	!n.neg && (tag.flags & PLUS) ? write(1, "+", 1) : 0;
	!n.neg && !(tag.flags & PLUS) && (tag.flags & SPACE) ? write(1, " ", 1) : 0;
	if (tag.width != -1 && !(tag.flags & MINUS) && (tag.flags & ZEROES))
		padding(n.width - n.size
				- ((tag.flags & (PLUS | SPACE)) || n.neg ? 1 : 0), 1);
	write(1, &(n.nbr[n.neg]), (n.size > ft_strlen(&(n.nbr[n.neg])) ?
			ft_strlen(&(n.nbr[n.neg])) : n.size));
	if ((!n.precision && (tag.flags & HASHTAG) && n.nbr[n.size - 1] != '.')
			|| (n.precision && ft_strchr(n.nbr, '.') == -1))
		write(1, ".", 1);
	if (n.size > ft_strlen(&(n.nbr[n.neg])) + ((tag.flags & HASHTAG) ? 1 : 0))
		padding(n.size - ft_strlen(&(n.nbr[n.neg])), 1);
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(n.width - n.size
				- ((tag.flags & (PLUS | SPACE)) || n.neg ? 1 : 0), 0);
}
*/
/*
void rounding(char *nbr, int precision)
{
	int value;
	int i;

	i = 0;
	if (!precision)
		return ;
	while (*nbr != '.')
		nbr++;
	while (precision-- >= 0 && *nbr)
		nbr++;
	if (!nbr)
		return ;
	printf(">%c\n", *nbr);
	value = *nbr - 48
	while (value == 5 && nbr[++i])
		value += nbr[i] - 48;
	i = 1;
	if (value > 5)
	{
		while (*(nbr - i) == '9' || *(nbr - i) == '.')
			i++;
		
	}
	return ;
}
*/

void	rounding(t_nbr *n)
{
	int value;
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	while (n->nbr[i] != '.')
		i++;
	while (j <= n->precision && n->nbr[++i])
		j++;
	if (!n->nbr[i])
		return ;
	tmp = i - 1;
	value = n->nbr[i] - 48;
	while (value == 5 && n->nbr[++i])
		value += n->nbr[i] - 48;
	i = tmp;
	if (value > 5)
	{
		while (i >= n->neg && (n->nbr[i] == '9' || n->nbr[i] == '.'))
		{
			if (n->nbr[i] == '9')
				n->nbr[i] = '0';
			i--;
		}
		if (i < n->neg)
		{
			n->nbr = ft_strjoin(n->neg ? "-1" : "1", &(n->nbr[n->neg]));
			n->size++;
		}
		else
			n->nbr[i] += 1;
	}
	return ;
}

void 	print_special(t_tag tag, t_nbr n)
{
	if (!ft_strncmp(n.nbr, "nan", 3))
		tag.flags = (tag.flags & ~PLUS) & ~SPACE;
	if (tag.width != -1 && !(tag.flags & MINUS))
		padding(n.width - 3 - ((tag.flags & (PLUS | SPACE)) || n.neg), 0);
	n.neg ? write(1, "-", 1) : 0;
	!n.neg && (tag.flags & PLUS) ? write(1, "+", 1) : 0;
	!n.neg && !(tag.flags & PLUS) && (tag.flags & SPACE) ? write(1, " ", 1) : 0;
	write(1, &(n.nbr[n.neg]), 3);
	if (tag.width != -1 && (tag.flags & MINUS))
		padding(n.width - 3 - ((tag.flags & (PLUS | SPACE)) || n.neg), 0);
}
void	print_float(t_tag tag, t_nbr n)
{
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

}
int		print_double(t_tag tag, va_list ap)
{
	t_nbr	n;

	n.width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	n.precision = n.precision < 0 ? 6 : n.precision;
	n.nbr = ftoa(va_arg(ap, double));
	n.neg = *(n.nbr) == '-' ? 1 : 0;
	tag.flags = n.width < 0 && tag.width != -1 ? tag.flags | MINUS : tag.flags;
	n.width = n.width < 0 && tag.width != -1 ? -n.width : n.width;
	n.size = ft_strlen(ft_split(&(n.nbr[n.neg]), '.')[0]) + n.precision
		+ ((tag.flags & HASHTAG) || n.precision);
//	printf("\n>>%s, %d, %d, %d, %d\n", n.nbr, n.width, n.precision, n.size, n.neg);
	if (ft_isdigit(n.nbr[0]) || (n.nbr[0] == '-' && ft_isdigit(n.nbr[1])))
	{
		rounding(&n);
		print_float(tag, n);
	}
	else
		print_special(tag, n);
	return (ft_strlen(n.nbr));
}
