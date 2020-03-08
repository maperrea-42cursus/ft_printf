/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:41:28 by maperrea          #+#    #+#             */
/*   Updated: 2020/03/07 10:29:11 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#define INPUT "% +d|\n", 123

int main()
{
	int ret_libc = 1;
	int ret = 1;
	ret = ft_printf(INPUT);
	ret_libc = printf(INPUT);
	printf("ret = %d\nret_libc = %d\n", ret, ret_libc);
	
//	write(1, "\033[38;5;2mabc\033[0m\n", 20);
//	ft_printf("%s|\n%s|\n", ft_reverse_str("abcdef"), ft_reverse_str("abcdefg"));
//	printf("%.50lf\n%.50lf\n", (float)123.123, (double)123.123);
}

