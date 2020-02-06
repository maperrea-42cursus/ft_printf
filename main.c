/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:41:28 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/06 22:26:12 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#define INPUT "%010%|\n"

int main()
{
//	printf(">>%p<<\n", &i);
	int ret_libc = 1;
	int ret;
	ret = ft_printf(INPUT);
	ret_libc = printf(INPUT);
	ft_printf("ret = %d\nret_libc = %d\n", ret, ret_libc);
	
}
