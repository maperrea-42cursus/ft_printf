/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:45:17 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/11 18:53:12 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_exp(long long nbr, int exp)
{
	long long out;

	out = nbr;
	while (exp - 1)
	{
		out *= nbr;
		exp--;
	}
	return (out);
}
