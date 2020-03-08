/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 22:19:04 by maperrea          #+#    #+#             */
/*   Updated: 2020/03/07 13:00:14 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "big_number.h"

void			print_bits(void *ptr, int size)
{
	int i;
	int j;

	i = 0;
	j = 0b10000000;
	while (i < size)
	{
		*(unsigned char *)ptr & j ? write(1, "1", 1) : write(1, "0", 1);
		i++;
		j >>= 1;
		if (j & 0b00001000)
			write(1, " ", 1);
		if (!j && i < size)
		{
			ptr++;
			j = 0b10000000;
			write(1, " | ", 3);
		}
	}
}

void			print_bn(t_big_number *bn)
{
	int i;

	printf("negative? : %d\n", bn->sign);
	i = bn->int_size;
	printf("int_size: %d\n", i);
	while (i > 0)
	{
		printf("%.2hhx", (bn->int_part)[i-- - 1]);
		if (i <= 0)
			break;
		printf(" | ");
	}
	printf("\n");
	i = bn->decimal_size;
	printf("decimal_size: %d\n", i);
	while (i > 0)
	{
		printf("%.2hhx", (bn->decimal_part)[i-- - 1]);
		if (i <= 0)
			break;
		printf(" | ");
	}
	printf("\n");
}

void			print_dbl_bits(double d)
{
	unsigned char *tmp;
	int i;
	int j;

	tmp = (unsigned char *)&d;
	if (tmp[7] & 0b10000000)
		write(1, "sign : 1\n", 9);
	else
		write(1, "sign : 0\n", 9);
	i = 1 << 6;
	write(1, "exponent : ", 11);
	while (i)
	{
		tmp[7] & i ? write(1, "1", 1) : write(1, "0", 1);
		i >>= 1;
	}
	i = 1 << 7;
	while (i > 1 << 3)
	{
		tmp[6] & i ? write(1, "1", 1) : write(1, "0", 1);
		i >>= 1;
	}
	j = 6;
	write(1, "\nmantissa : ", 12);
	while (j >= 0)
	{
		tmp[j] & i ? write(1, "1", 1) : write (1, "0", 1);
		i >>= 1;
		if (!i)
		{
			i = 1 << 7;
			j--;
		}
	}
	write(1, "\n", 1);
}
