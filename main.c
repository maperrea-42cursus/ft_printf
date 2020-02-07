/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:41:28 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/07 01:46:37 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#define INPUT "%10.0d|\n", 0


int main()
{
//	printf(">>%s<<\n", NULL);
	int ret_libc = 1;
	int ret;
	ret = ft_printf(INPUT);
	ret_libc = printf(INPUT);
	printf("ret = %d\nret_libc = %d\n", ret, ret_libc);
	
}

//TODO valeur de retour avec n = 0 et preci = 0 mais un width
