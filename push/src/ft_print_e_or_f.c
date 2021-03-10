/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_e_or_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:47:40 by maperrea          #+#    #+#             */
/*   Updated: 2020/10/02 13:48:49 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		trimmed_size(t_nbr n)
{
	int i;

	if (ft_strlen(&n.nbr[n.neg]) <= n.precision + 1)
		return ((ft_strlen(&n.nbr[n.neg])));
	i = n.precision;
	while (n.nbr[n.neg + i] == '0')
		i--;
	i += (i == 0);
	return (i + 1);
}

int		leading_zeroes(t_nbr n)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (n.nbr[n.neg + i] == '0' || n.nbr[n.neg + i] == '.')
	{
		if (n.nbr[n.neg + i] == '0')
			count++;
		i++;
	}
	if (!n.nbr[n.neg + i])
		return (0);
	return (count);
}

int		to_f(t_tag tag, t_nbr n)
{
	t_nbr new;

	n.precision += leading_zeroes(n);
	new = (t_nbr){n.nbr, n.width, n.precision, n.size, n.neg};
	new.precision = n.precision - ft_strlen(ft_split(&(n.nbr[n.neg]), '.')[0]);
	new.size = rounding(&new);
	new.size += ((trimmed_size(n) - 1 < n.precision ?
								trimmed_size(n) - 1 : n.precision)
		+ (new.precision > 0 && n.nbr[n.neg + trimmed_size(n) - 1] != '.'))
		* ((tag.flags & HASHTAG) == 0)
		+ (n.precision + 1) * ((tag.flags & HASHTAG) != 0);
	return (print_float(tag, new));
}

int		to_e(t_tag tag, t_nbr n)
{
	t_nbr	new;
	int		exp;

	new = (t_nbr){n.nbr, n.width, n.precision, n.size, n.neg};
	new.precision = n.precision - 1;
	exp = move_comma(&new);
	exp += rounding(&new);
	move_comma(&new);
	n.nbr = new.nbr;
	new.size = ((trimmed_size(n) - 1 < n.precision ?
								trimmed_size(n) - 1 : n.precision)
		+ (new.precision > 0 && n.nbr[n.neg + trimmed_size(n) - 1] != '.'))
		* ((tag.flags & HASHTAG) == 0)
		+ (n.precision + 1) * ((tag.flags & HASHTAG) != 0);
	return (print_exp(tag, new, exp));
}

int		print_e_or_f(t_tag tag, va_list ap)
{
	t_nbr	n;
	t_nbr	n_dup;
	int		exp;

	if (!(n.nbr = ftoa(va_arg(ap, double))))
		return (0);
	n.width = tag.width == -2 ? va_arg(ap, int) : tag.width;
	n.precision = tag.precision == -2 ? va_arg(ap, int) : tag.precision;
	n.precision = n.precision < 0 ? 6 : n.precision;
	n.precision = n.precision == 0 ? 1 : n.precision;
	n.neg = (*(n.nbr) == '-');
	tag.flags = n.width < 0 && tag.width != -1 ? tag.flags | MINUS : tag.flags;
	n.width = n.width < 0 && tag.width != -1 ? -n.width : n.width;
	if (!ft_isdigit(n.nbr[n.neg]))
		return (print_special(tag, n));
	if (!(n_dup = (t_nbr){ft_strdup(n.nbr), n.width, n.precision
		- ft_strlen(ft_split(&(n.nbr[n.neg]), '.')[0]), 0, n.neg}).nbr)
		return (0);
	exp = move_comma(&n_dup) + rounding(&n_dup);
	if (!(n_dup.nbr = ft_strdup(n.nbr)))
		return (0);
	return ((exp < -4 || exp >= n.precision + 4
	|| n_dup.precision - rounding(&n_dup) < 0) ? to_e(tag, n) : to_f(tag, n));
}
