/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:16:16 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/15 20:37:38 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print(double f, int precision, int count)
{
	char	c;

	if (f * ft_exp(10, precision) >= 10)
	{
		print(f / 10, precision, count + 1);
		c = ((long)(f * ft_exp(10, precision)) % 10) + 48;
	}
	else
		c = (long) (f * ft_exp(10, precision)) + 48;
	if (count == precision - 1)
		write(1, ".", 1);
	if (c != 40)
		write(1, &c, 1);
	else
		write(1, "0", 1);
}

void		ft_putfloat(double f, int precision)
{
	print(f, precision, 0);
}
