/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:41:28 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/15 20:36:42 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#define INPUT "%x|\n", -123456789

int main()
{
/*	int ret_libc = 1;
	int ret;
	ret = ft_printf(INPUT);
	ret_libc = printf(INPUT);
	printf("ret = %d\nret_libc = %d\n", ret, ret_libc);
	*/
	printf("%.6f\n", 123456789123456789123456789.);
	ft_putfloat(123456789123456789123456789., 6);
}

