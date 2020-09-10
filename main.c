/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:41:28 by maperrea          #+#    #+#             */
/*   Updated: 2020/09/10 20:49:48 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#define INPUT "a|\n"

int main()
{
/*	int ret_libc = 1;
	int ret = 1;
	ret = ft_printf(INPUT);
	ret_libc = printf(INPUT);
	printf("ret = %d\nret_libc = %d\n", ret, ret_libc);
	char *str = ftoa(255.);
	printf(str);*/
	double f = 0.;
/*	char *ptr = (char*)&f;
	ptr[7] = 0b11111111;
	ptr[6] = 0b11110000;
	ptr[5] = 0b00000000;
	ptr[4] = 0b00000000;
	ptr[3] = 0b00000000;
	ptr[2] = 0b00000000;
	ptr[1] = 0b00000000;
	ptr[0] = 0b00000000;*/
/*	int i = 0;
	printf("%f\n%s\n", f, ftoa(f));*/
	printf("%.*d\n", -10, 123);
	ft_printf("%.*d\n", -10, 123);
	
//	write(1, "\033[38;5;2mabc\033[0m\n", 20);
//	ft_printf("%s|\n%s|\n", ft_reverse_str("abcdef"), ft_reverse_str("abcdefg"));
//	printf("%.50lf\n%.50lf\n", (float)123.123, (double)123.123);
	CHECK_LEAKS;
}

