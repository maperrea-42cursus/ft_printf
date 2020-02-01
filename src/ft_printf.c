/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:51:20 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/01 04:58:54 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list ap;

	va_start(ap, str);
	return (1);
}

int main()
{
	char	*str = "abcd%0 15.5lldefghi%#+15.5j%%kl%+%";
	t_tag	tag;

	while (parse_str(&str, &tag) == 1)
		printf("\n>>flags = %d\n>>width = %d\n>>precision = %d\n>>length = %d\n>>specifier = %d\n", tag.flags, tag.width, tag.precision, tag.length, tag.specifier);
	printf("\n>>flags = %d\n>>width = %d\n>>precision = %d\n>>length = %d\n>>specifier = %d\n", tag.flags, tag.width, tag.precision, tag.length, tag.specifier);
}
