/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:58:02 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/04 18:03:25 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	padding(int size, int zeroes)
{
	char	c;
	int		i;

	c = zeroes ? '0' : ' ';
	i = 0;
	while (i < size)
	{
		write(1, &c, 1);
		i++;
	}
}
